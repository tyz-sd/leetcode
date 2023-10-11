#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        int length = graph.size();
        int count = 0;
        bool visited[10001];
        bool is_unsafe[10001];
        for(int i = 0 ; i < length ; i ++){
            visited[i] = 0;
            is_unsafe[i] = 0;
            if(graph[i].size() == 0){
                result.push_back(i);
                count++;
                visited[i] = 1;
            }
        }
        while(count != length){
            int succ_cnt = count;
            for(int i = 0 ; i < length ; i++){
                if(!visited[i]){
                    int flg = 1;
                    for(int j = 0 ; j < graph[i].size() ; j ++){
                        if(is_unsafe[graph[i][j]] || graph[i][j] == i){
                            is_unsafe[i] = 1;
                            visited[i] = 1;
                            count++;
                            flg = 0;
                            break;
                        }
                        if(!visited[graph[i][j]]){flg = 0;}
                    }
                    if(flg){
                        visited[i] = 1;
                        count++;
                        result.push_back(i);
                    }
                }
            }
            if(count == succ_cnt){break;}
        }
        sort(result.begin(), result.end());
        return result;
    }
};

// attempt1: 518ms: too slow

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        int length = graph.size();
        vector<int> size(length);
        vector<vector<int> > r_graph(length);
        queue<int> node_q;
        for(int i = 0 ; i < length ; i ++){
            size[i] = graph[i].size();
            if(size[i] == 0){
                result.push_back(i);
                node_q.push(i);
            }
            for(int j : graph[i]){
                r_graph[j].push_back(i);
            }
        }
        while(!node_q.empty()){
            int safe_node = node_q.front();
            node_q.pop();
            for(int i : r_graph[safe_node]){
                size[i] -= 1;
                if(!size[i]){
                    result.push_back(i);
                    node_q.push(i);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

//attempt2: use recursive graph 211ms 61.4MB

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        int length = graph.size();
        vector<int> visited(length),dfs_visited(length),in_loop(length);
        for(int i = 0 ; i < length ; i ++){
            if(!visited[i]){
                dfs(i, visited, dfs_visited, in_loop, graph);
            }
        }
        for(int i = 0 ; i < length ; i ++){
            if(!in_loop[i]){
                result.push_back(i);
            }
        }
        return result;
    }
    bool dfs(int node, vector<int>& visited, vector<int>& dfs_visited, vector<int>& loop,
        vector<vector<int> >& graph){
        visited[node] = 1;
        dfs_visited[node] = 1;
        for(int i : graph[node]){
            if(!visited[i]){
                if(dfs(i, visited, dfs_visited, loop, graph)){
                    loop[node] = 1;
                    return true;
                }
            }
            else{
                if(loop[i] || dfs_visited[i]){
                    loop[node] = 1;
                    return true;
                }
            }
        }
        dfs_visited[node] = 0;
        return false;
    }
};

//attempt3: use dfs to detect loop : 151ms && 48.2MB