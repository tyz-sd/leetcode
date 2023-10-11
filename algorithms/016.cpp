#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int threeSumClosest(vector<int>& nums, int _target) {
    sort(nums.begin(), nums.end());
    int nearest_sum = 0x7fffffff;
    for(int i = 0 ; i < nums.size() - 2;){
        int j = i + 1;
        int k = nums.size() - 1;
        int target = _target - nums[i];
        while(j < k){
            if(nums[j] + nums[k] == target){
                cout<<i<<" "<<j<<" "<<k<<endl;
                return _target;
            }
            if(nums[j] + nums[k] > target){
                nearest_sum = min(nearest_sum, nums[j] + nums[k] - target);
                k--;
            }
            else{
                nearest_sum = min(nearest_sum, - nums[j] - nums[k] + target);
                j++;
            }
        }
        int newi = i;
        while(newi < k && nums[newi] == nums[i]){
            newi++;
        }
        i = newi;
    }
    return nearest_sum;
}
int main(){
    vector<int> vec = {-1,2,1,-4};
    cout<<threeSumClosest(vec, 1)<<endl;
    return 0;
}