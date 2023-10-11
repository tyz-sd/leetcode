class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> front_product(length, 1);
        vector<int> back_product(length, 1);
        vector<int> answer(length);
        for(int i = 1 ; i < length ; i++){
            front_product[i] = front_product[i-1] * nums[i-1];
            back_product[length-i-1] = back_product[length-i] * nums[length-i];
        }
        for(int i = 0 ; i < length ; i++){
            answer[i] = front_product[i] * back_product[i];
        }
        return answer;
    }
};

//On On