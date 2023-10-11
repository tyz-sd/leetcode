class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; 
        int length = nums.size();
        vector<int> new_nums(length);
        for(int i = 0 ; i < length ;){
            int cur_num = nums[i];
            bool flag = true;
            new_nums[k++] = nums[i++];
            while(i < length && nums[i] == cur_num){
                if(flag){
                    flag = false;
                    new_nums[k++] = nums[i];
                }
                i++;
            }
        }
        for(int i = 0 ;i < k ; i++){
            nums[i] = new_nums[i];
        }
        return k;
    }
};