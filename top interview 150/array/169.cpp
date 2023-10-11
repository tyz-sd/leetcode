class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int length = nums.size();
        int major = 0;
        int count = 0;
        for(int i = 0 ; i < length ; i ++){
            if(count == 0) {
                major = nums[i];
                count++;
            }
            else {
                if(nums[i] == major) count++;
                else count--;
            }
        }
        return major;
    }
};