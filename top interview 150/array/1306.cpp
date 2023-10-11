class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0) return true;
        int length = arr.size();
        queue<int> q;
        vector<int> visited(length, 0);
        q.push(start);
        while(!q.empty()){
            int cur_node = q.front();
            q.pop();
            visited[cur_node] = 1;
            int jmp = arr[cur_node];
            if(cur_node + jmp <= length - 1 && !visited[cur_node + jmp]){
                if(arr[cur_node + jmp] == 0) return true;
                q.push(cur_node + jmp);
            }
            if(cur_node - jmp >= 0 && !visited[cur_node - jmp]){
                if(arr[cur_node - jmp] == 0) return true;
                q.push(cur_node - jmp);
            }
        }
        return false;
    }
};