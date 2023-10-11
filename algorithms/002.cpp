#include<iostream>
#include<string>
#include<map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int length = s.length();
    for(int i = 0 ; i < length ; i++){
        if(s.substr(i + 1, length - 1 - i).find(s[i]) != s.npos){
            int pos = s.substr(i + 1, length - 1 - i).find(s[i]);
            cout<<pos<<endl;
            cout<<s.substr(i + 1, length - 1 - i)<<endl;
            cout<<s.substr(0, pos)<<endl;
            return max(lengthOfLongestSubstring(s.substr(i + 1, length - 1 - i)), 
            lengthOfLongestSubstring(s.substr(0, pos)));
        }
    }
    return length;
}
int main(){
    cout<<lengthOfLongestSubstring("uqinntq")<<endl;
}


class Solution {
public:
    int max_length = 0;
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        if(length <= max_length) return 0;
        for(int i = 0 ; i < length ; i++){
            if(s.substr(i + 1, length - 1 - i).find(s[i]) != s.npos){
                int pos = s.substr(i + 1, length - 1 - i).find(s[i]) + i + 1;
                if((pos <= max_length && length - 1 - i <= max_length)){
                    return 0;
                }
                else if(pos <= max_length){
                    max_length = max(max_length, lengthOfLongestSubstring(s.substr(i + 1, length - 1 - i)));
                    return max_length;
                }
                else if(length - 1 - i <= max_length){
                    max_length = max(max_length, lengthOfLongestSubstring(s.substr(0, pos)));
                    return max_length;
                }
                else{
                    int len = max(lengthOfLongestSubstring(s.substr(i + 1, length - 1 - i)), 
                lengthOfLongestSubstring(s.substr(0, pos)));
                    max_length = max(max_length, len);
                    return max_length;
                }
            }
        }
        return length;
    }
};


// attempt1: MLE

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        queue<pair<int, int> > q;
        q.push(make_pair(0, s.length()));
        while(!q.empty()){
            bool flg = true;
            pair<int, int> top = q.front();
            q.pop();
            if(top.second <= max_length){continue;}
            for(int i = top.first ; i < top.first + top.second ; i++){
                if(s.substr(i + 1, top.first + top.second - i - 1).find(s[i]) != s.npos){
                    int pos = s.substr(i + 1, top.first + top.second - i - 1).find(s[i]) + i + 1 - top.first;
                    if(pos > max_length)
                        q.push(make_pair(top.first, pos));
                    if(top.second + top.first - i - 1 > max_length)
                        q.push(make_pair(i + 1, top.second + top.first - i - 1));
                    flg = false;
                    break;
                }
            }
            if(flg){
                max_length = max(max_length, top.second);
            }
        }
        return max_length;
    }
};

// attempt2: MLE

#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 1;
        int left = 0;
        int right = 0;
        unordered_map<char, int> position;
        if(s.length() == 0){return 0;}
        for(int i = 0 ; i < s.length() ; i ++){
            if(position.find(s[i]) == position.end())
                position.insert(make_pair(s[i], -1));
        }
        position[s[0]] = 0;
        while(right < s.length() - 1){
            right += 1;
            if(position[s[right]] < left){
                position[s[right]] = right;
                max_length = max(max_length, right - left + 1);
            }
            else{
                left = position[s[right]] + 1;
                position[s[right]] = right;
                max_length = max(1, max_length);
            }
        }
        return max_length;
    }
};

// attempt3: AC 24ms 8.3MB

