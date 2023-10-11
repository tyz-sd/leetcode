#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> result;
    int path[1001][1001];
    int valid[1001];
    int length = graph.size();
    for(int i = 0 ; i < length ; i ++){
        for(int j = 0  ; j < length ; j++){
            path[i][j] = -1;
        }
        valid[i] = 1;
    }
    for(int i = 0 ; i < length ; i++){
        for(int j = 0 ; j < graph[i].size() ; j++){
            path[i][graph[i][j]] = i;
            if(graph[i][j] == i) valid[i] = 0;
            for(int k = 0 ; k < i ; k++){
                if(path[k][i] != -1 || path[k][k] != -1){
                    if(k == graph[i][j]){
                        int l = path[k][i];
                        while(l != k && l != -1){
                            valid[l] = 0;
                            l = path[k][l];
                        }
                        valid[k] = 0;
                        valid[i] = 0;
                    }
                    else{
                        if(graph[i][j] != i)
                            path[k][graph[i][j]] = i;
                    }
                }
            }
        }
    }
    for(int i = 0 ; i < length ; i ++){
        if(valid[i]){
            result.push_back(i);
        }
    }
    return result;
}
int main(){
    vector<vector<int> > gra;
    gra.push_back({1,2});
    gra.push_back({2,3});
    gra.push_back({5});
    gra.push_back({0});
    gra.push_back({5});
    gra.push_back({});
    gra.push_back({});
    cout<<"good"<<endl;
    vector<int> res = eventualSafeNodes(gra);
    for(int i = 0 ; i < res.size() ; i++){
        cout<< res[i]<<" ";
    }
    cout<<endl;
    return 0;
}