class Solution {
public:
    int jump(vector<int>& nums) {
        int can = 0;
        int length = nums.size();
        int last_can = 0;
        int cnt = 0;
        while(can < length - 1){
            int max_jmp = 0;
            for(int i = last_can ; i <= can ; i++){
                max_jmp = max(max_jmp, nums[i] + i - can);
            }
            cnt += 1;
            last_can = can + 1;
            can += max_jmp;
        }
        return cnt;
    }
};