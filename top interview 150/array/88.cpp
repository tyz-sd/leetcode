#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = 0;
        int pos2 = 0;
        int total_pos = 0;
        vector<int> result(m+n);
        while(pos1 < m && pos2 < n){
            if(nums1[pos1] <= nums2[pos2]) result[total_pos++] = nums1[pos1++];
            else result[total_pos++] = nums2[pos2++];
        }
        while(pos1 < m)  result[total_pos++] = nums1[pos1++];
        while(pos2 < n)  result[total_pos++] = nums2[pos2++];
        for(int i = 0 ; i < m + n ; i ++)
            nums1[i] = result[i];
        return;
    }
};