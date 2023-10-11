#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int count[0x7f];
        int total_count = 0;
        for(int i = 0 ; i < 0x7f ; i++){
            count[i] = 0x7fffffff;
        }
        int m = s.length();
        int n = t.length();
        for(int i = 0 ; i < n ; i++){
            count[(int)t[i]] = count[(int)t[i]] == 0x7fffffff ? 1 : count[(int)t[i]] + 1;
            total_count += 1;
        }
        int left = 0;
        int right = 0;
        int min_length = 0x7fffffff;
        int min_left = -1;
        int min_right = -1;
        while(right < m){
            if(count[(int)s[right]] == 0x7fffffff){
                right += 1;
                continue;
            }
            else if(count[(int)s[right]] >= 1){
                total_count -= 1;
            }
            count[(int)s[right]] -= 1;
            while(total_count == 0){
                if(right - left + 1 < min_length){
                    min_length = right - left + 1;
                    min_left = left;
                    min_right = right;
                }
                if(count[(int)s[left]] == 0x7fffffff){
                    left ++;
                }
                else{
                    count[(int)s[left]] += 1;
                    if(count[(int)s[left]] >= 1)
                        total_count += 1;
                    left ++;
                }
            }
            right += 1;
        }
        return min_left < 0 ? "" : s.substr(min_left, min_right - min_left + 1);
    }
};

//attempt1: sliding windows 8ms ; 7.8 MB