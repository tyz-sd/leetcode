#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        vector<int> new_nums(length);
        int k = 0;
        for(int i = 0 ; i < length ; i++){
            int cur_num = nums[i];
            new_nums[k++] = nums[i];
            while(i < length && nums[i] == cur_num){
                i++;
            }
            i--;
        }
        for(int i = 0 ; i < k ; i++){
            nums[i] = new_nums[i];
        }
        return k;
    }
};