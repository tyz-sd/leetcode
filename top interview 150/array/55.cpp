class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        vector<int> can(length, 0);
        can[0] = 1;
        for(int i = 0 ; i < length ; i++){
            if(can[i]){
                if(i + nums[i] >= length - 1) return true;
                else{
                    for(int j = 1 ; j <= nums[i] ; j++){
                        can[i+j] = true;
                    }
                }
            }
        }
        return false;
    }
};