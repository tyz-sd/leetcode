class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int _target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if(nums.size() < 4){return result;}
        int j, k;
        for(int i = 0 ; i < nums.size() - 3;){
            for(int l = i + 1 ; l < nums.size() - 2;){
                j = l + 1;
                k = nums.size() - 1;
                long target = (long)_target - (long)nums[i] - (long)nums[l];
                while(j < k){
                    if(nums[j] + nums[k] == target){
                        result.push_back({nums[i], nums[l], nums[j], nums[k]});
                        int newj = j;
                        while(newj < k && nums[newj] == nums[j]){
                            newj++;
                        }
                        j = newj;
                        continue;
                    }
                    if(nums[j] + nums[k] > target){
                        k--;
                    }
                    else{
                        j++;
                    }
                }
                int newl = l;
                while(newl < k && nums[newl] == nums[l]){
                    newl++;
                }
                l = newl;
            }
            int newi = i;
            while(newi < k && nums[newi] == nums[i]){
                newi++;
            }
            i = newi;
        }
        return result;
    }
};