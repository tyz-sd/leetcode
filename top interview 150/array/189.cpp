class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> new_nums(length);
        for(int i = 0 ; i < length ; i++){
            new_nums[(i+k)%length] = nums[i];
        }
        for(int i = 0 ; i < length ; i++){
            nums[i] = new_nums[i];
        }
        return;
    }
};

//attempt1 : On On


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int cur_position = 0;
        int tmp_position = 0;
        int cur_num;
        int length = nums.size();
        int steps = length % k == 0 ? length / k : 1;
        int r_length = length - k;
        for(int i = 0 ; i < steps ; i++){
            tmp_position = cur_position;
            do{
                cur_num = nums[cur_position];
                int tmp_position2 = (tmp_position + r_length) % length;
                nums[tmp_position] = tmp_position2 == cur_position ? cur_num : nums[tmp_position2];
                tmp_position = tmp_position2;
            }
            while(tmp_position != cur_position);
            cur_position ++;
        }
    }
};

//attempt2: why wrong??


