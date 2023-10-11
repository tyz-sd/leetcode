#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for(int i = 0 ; i < nums.size() - 2;){
        int j = i + 1;
        int k = nums.size() - 1;
        int target = 0 - nums[i];
        while(j < k){
            if(nums[j] + nums[k] == target){
                result.push_back({nums[i], nums[j], nums[k]});
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
        int newi = i;
        while(newi < k && nums[newi] == nums[i]){
            newi++;
        }
        i = newi;
    }
    return result;
}

int main(){
    vector<int> sum = {0,-1,1};
    threeSum(sum);
    cout<<"end"<<endl;
    return 0;
}