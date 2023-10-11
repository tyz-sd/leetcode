#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
int res = 0;
int cmp(string a, string b){
    int length_a = a.length();
    int length_b = b.length();
    if(length_a > length_b) return 1;
    else if(length_a < length_b) return -1;
    else{
        for(int i = 0 ; i < length_a ; i ++){
            if(a[i] > b[i]) return 1;
            else if(a[i] < b[i]) return -1;
        }
    }
    return 0;
}
void dfs(string low, string high, string step_num){
    if((cmp(step_num, low) == 1 || cmp(step_num, low) == 0) && (cmp(step_num, high) == -1 || cmp(step_num, high) == 0)){
        res += 1;
        cout<<step_num<<endl;
    }
    if(cmp(step_num, high) == 1) return ;
    
    int length = step_num.length();
    char i = step_num[length - 1];
    if(i == '0'){
        dfs(low, high, step_num+'1');
    }
    if(i == '9'){
        dfs(low, high, step_num+'8');
    }
    else{
        dfs(low, high, step_num+(char)((int)i-1));
        dfs(low, high, step_num+(char)((int)i+1));
    }
}
int countSteppingNumbers(string low, string high) {
    string str = "";
    for(char i = '1' ; i <= '9' ; i++){
        dfs(low, high, str+i);
    }
    return res;
}
bool canSplitArray(vector<int>& nums, int m) {
    int length = nums.size();
    vector<vector<int> > sums(length, vector<int>(length, 0));
    vector<vector<int> > dp(length, vector<int>(length, 0));
    for(int i = 0 ; i < length ; i++){
        if(i == 0)
            sums[0][i] += nums[i];
        else
            sums[0][i] = sums[0][i-1] + nums[i];
        for(int j = 1 ; j <= i ; j++){
            sums[j][i] = sums[j-1][i] - nums[j-1];
            cout<<"sums: "<<j<<" "<<i<<" "<<sums[j][i]<<endl;
        }
        cout<<"sums: "<<0<<" "<<i<<" "<<sums[0][i]<<endl;
        dp[i][i] = 1;
        cout<<"shit"<<" "<<sums[0][1]<<endl;
    }
    cout<<"shit"<<" "<<sums[0][1]<<endl;
    for(int l = 1 ; l < length ; l++)
        for(int i = 0 ; i < length - l; i++){
            if((dp[i][i+l-1] == 1 && (l == 1 || sums[i][i+l-1] >= m))|| (dp[i+1][i+l] == 1 && (l == 1 || sums[i+1][i+l] >= m))){
                cout<< i << " " << i + l - 1 << " " << sums[i][i+l-1] << " " << sums[i+1][i+l]<<endl;
                cout<<"path1: "<< i << " " << l << " " << sums[i][i+l]<<endl;
                dp[i][i+l] = 1;
            }
            else{
                for(int j = i+l-1 ; j >= i + 1 ; j-- ){
                    if(dp[i][j-1] == 1 && sums[i][j-1] >= m && dp[j][i+l] == 1 && sums[j][i+l] >= m) dp[i][i+l] = 1;
                }
            }
            cout<< i << " " << l << " " << dp[i][i+l]<<endl;
        }
    if(dp[0][length - 1] == 1)return true;
    return false;
}
int cal(vector<pair<int,int>> & thieves, int i, int j){
    int min_len = 0x7fffffff;
    for(int i = 0 ; i < thieves.size() ; i++){
        min_len = min(min_len, abs(thieves[i].first-i) + abs(thieves[i].second-j));
    }
    return min_len;
}
int dfs(vector<pair<int,int>> & thieves, int i, int j, int len, int length, vector<vector<int>> & visited){
    if(cal(thieves, i, j) < len){
        return false;
    }
    if(i == length - 1 && j == length - 1) return true;
    else{
        int can = 0;
        if(i + 1 >= 0 && i + 1 < length && !visited[i+1][j]){
            visited[i+1][j] = 1;
            can += dfs(thieves, i+1, j, len, length, visited);
            visited[i+1][j] = 0;
            cout<<i+1<<" "<<j<<" "<<can<<endl;
        }
        if(i - 1 >= 0 && i - 1 < length && !visited[i-1][j]){
            visited[i-1][j] = 1;
            can += dfs(thieves, i-1, j, len, length, visited);
            visited[i-1][j] = 0;
            cout<<i-1<<" "<<j<<" "<<can<<endl;
        }
        if(j + 1 >= 0 && j + 1 < length && !visited[i][j+1]){
            visited[i][j+1] = 1;
            can += dfs(thieves, i, j+1, len, length, visited);
            visited[i][j+1] = 0;
            cout<<i<<" "<<j+1<<" "<<can<<endl;
        }
        if(j - 1 >= 0 && j - 1 < length && !visited[i][j-1]){
            visited[i][j-1] = 1;
            can += dfs(thieves, i, j-1, len, length, visited);
            visited[i][j-1] = 0;
            cout<<i<<" "<<j-1<<" "<<can<<endl;
        }
        return can != 0;
    }
}
int maximumSafenessFactor(vector<vector<int>>& grid) {
    int length = grid.size();
    vector<pair<int,int>> thieves;
    for(int i = 0 ; i < length ; i ++){
        for(int j = 0 ; j < length ; j ++){
            if(grid[i][j] == 1) thieves.push_back(make_pair(i,j));
        }
    }
    for(int i = length - 1 ; i >= 0 ; i--){
        vector<vector<int>> visited(length, vector<int>(length, 0));
        visited[0][0] = 1;
        if(dfs(thieves,0,0,i,length,visited) != 0){
            cout<<"can:: "<<i<<endl;
            return i;
        }
    }
    return 0;
}
int main(){
    //countSteppingNumbers("90", "101");
    vector<vector<int>> array = {{0,0,1}, {0,0,0}, {0,0,0}};
    cout<<maximumSafenessFactor(array);
    cout<<(1+2)/2<<endl;
}