#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = nums.size();
        int left = 0;
        int min_length = 0x7fffffff;
        int sum = 0;
        for(int i = 0 ; i < length ; i++){
            if(nums[i] >= target) return 1;
            sum = sum + nums[i];
            while(sum >= target){
                min_length = min(min_length, i - left + 1);
                sum -= nums[left++];
            }
        }
        return min_length == 0x7fffffff ? 0 : min_length;
    }
};