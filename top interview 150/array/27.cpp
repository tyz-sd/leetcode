#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int length = nums.size();
        vector<int> new_nums(length);
        for(int i = 0 ; i < length ; i ++){
            if(nums[i] != val){new_nums[k++] = nums[i];}
        }
        for(int i = 0 ; i < k ; i ++){
            nums[i] = new_nums[i];
        }
        return k;
    }
};