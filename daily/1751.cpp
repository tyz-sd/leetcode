#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int length = events.size();
        multimap<int, int> eventmap_s;
        multimap<int, int> eventmap_e;
        map<int, int> time_table;
        for(int i = 0 ; i < length ; i++){
            eventmap_s.insert(make_pair(events[i][0], i));
            eventmap_e.insert(make_pair(events[i][1], i));
            time_table.insert(make_pair(events[i][0], 0));
            time_table.insert(make_pair(events[i][1], 0));
        }
        int time_table_length = time_table.size();
        int cnt = 0;
        for(auto i = time_table.begin() ; i != time_table.end() ; i++){
            i -> second = cnt;
            cnt++;
        }
        vector<vector<int> > dp_for_max_value(k + 1, vector<int>(time_table_length));
        for(int i = 0 ; i < time_table_length ; i++){
            for(int j = 0 ; j <= k ; j++){
                dp_for_max_value[j][i] = 0;
            }
        }
        for(auto i = eventmap_s.begin() ; i != eventmap_s.end() ; i++){
            int start_time = i->first;
            int end_time = events[i->second][1];
            int value = events[i->second][2];
            auto index_start = time_table.find(start_time);
            auto index_end = time_table.find(end_time);
            int index_start_time = index_start -> second;
            int index_end_time = index_end -> second;
            for(int j = 1 ; j <= k ; j++){
                if(index_start_time == 0 || j == 1)
                    dp_for_max_value[j][index_end_time] = max(dp_for_max_value[j][index_end_time], value);
                else{
                    int before_max_value = 0;
                    for(int l = 0 ; l < index_start_time ; l++){
                        before_max_value = max(before_max_value, dp_for_max_value[j - 1][l]);
                    }
                    dp_for_max_value[j][index_end_time] = max(dp_for_max_value[j][index_end_time], before_max_value + value);
                }
            }
        }
        int final_max_value = 0;
        for(auto i = 0 ; i < time_table_length ; i++){
            final_max_value = max(final_max_value, dp_for_max_value[k][i]);
        }
        return final_max_value;
    }
};

//attempt1 : time consuming On^2k

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int length = events.size();
        multimap<int, int> eventmap_s;
        map<int, int> time_table;
        for(int i = 0 ; i < length ; i++){
            eventmap_s.insert(make_pair(events[i][0], i));
            time_table.insert(make_pair(events[i][0], 0));
        }
        int time_table_length = time_table.size();
        int cnt = 0;
        for(auto i = time_table.begin() ; i != time_table.end() ; i++){
            i -> second = cnt;
            cnt++;
        }
        for(int i = 0 ; i < length ; i++){
            int end_time = events[i][1];
            map<int, int>::iterator index_end = time_table.upper_bound(end_time);
            index_end--;
            events[i][1] = index_end -> first;
        }
        vector<vector<int> > dp_for_max_value(k + 1, vector<int>(time_table_length));
        for(int i = 0 ; i < time_table_length ; i++){
            for(int j = 0 ; j <= k ; j++){
                dp_for_max_value[j][i] = 0;
            }
        }
        for(auto i = eventmap_s.begin() ; i != eventmap_s.end() ; i++){
            int start_time = i->first;
            int end_time = events[i->second][1];
            int value = events[i->second][2];
            int index_start_time = time_table[start_time];
            int index_end_time = time_table[end_time];
            for(int j = 1 ; j <= k ; j++){
                if(index_start_time == 0)
                    dp_for_max_value[j][index_end_time] = max(dp_for_max_value[j][index_end_time], value);
                else{
                    dp_for_max_value[j][index_start_time] = max(dp_for_max_value[j][index_start_time], dp_for_max_value[j][index_start_time - 1]);
                    if(j != 1)
                        dp_for_max_value[j][index_end_time] = max(dp_for_max_value[j][index_end_time], dp_for_max_value[j - 1][index_start_time - 1] + value);
                    else
                        dp_for_max_value[j][index_end_time] = max(dp_for_max_value[j][index_end_time], value);
                }
            }
        }
        return dp_for_max_value[k][time_table_length - 1];
    }
};

//attempt2 : Onlogn