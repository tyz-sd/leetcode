class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        int sum = 0;
        int left_max = 0;
        int right_max = 0;
        int left = 0;
        int right = length - 1;
        while(left <= right){
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if(left_max < right_max){
                while(left_max < right_max){
                    sum += left_max - height[left];
                    left++;
                    left_max = max(left_max, height[left]);
                }
            }
            else if(left_max > right_max){
                while(left_max > right_max){
                    sum += right_max - height[right];
                    right--;
                    right_max = max(right_max, height[right]);
                }
            }
            else{
                sum += right_max - height[left];
                left ++;
            }
        }
        return sum;
    }
};