#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int length = arr.size();
        vector<int> longest(length);
        int longest_size = 0;
        for(int i = 0 ; i < length ; i++){
            longest[i] = 1;
        }
        for(int i = 0 ; i < length ; i++){
            for(int j = i - 1 ; j >= 0 ; j--){
                if(arr[i] - arr[j] == difference){
                    longest[i] = max(longest[i], longest[j] + 1);
                    if(longest[i] >= longest_size + 1) break;
                }
            }
            longest_size = max(longest_size, longest[i]);
        }
        return longest_size;
    }
};

//attempt1: n^2 dp ： TLE