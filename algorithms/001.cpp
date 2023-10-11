#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums_map.find(nums[i]) == nums_map.end()){
                nums_map.insert(make_pair(target-nums[i],i));
            }
            else{
                return vector<int>({nums_map.find(nums[i])->second, i});
            }
        }
        return vector<int>();
    }
};

// 4ms 11MB