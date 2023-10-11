#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<bool> visited(m*n);
        bool exist = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                visited[i*m+j] = 0;
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!visited[i*m+j] && board[j][i] == word[0]){
                    if(word.length() == 1){return true;}
                    visited[i*m+j] = 1;
                    exist |= dfs(board, word.substr(1, word.length() - 1), m, n, i, j, visited);
                    visited[i*m+j] = 0;
                }
            }
        }
        return exist;
    }
    bool dfs(vector<vector<char> >& board, string word, int m, int n, int i, int j, vector<bool>& visited){
        bool exist = 0;
        int di = 0;
        int dj = 0;
        for(di = -1 ; di <= 1 ; di+=2){
            if(i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m && !visited[(i+di)*m+j+dj] && board[j+dj][i+di] == word[0]){
                if(word.length() == 1){return true;}
                visited[(i+di)*m+j+dj] = 1;
                exist |= dfs(board, word.substr(1, word.length() - 1), m, n, i+di, j+dj, visited);
                visited[(i+di)*m+j+dj] = 0;
            }
        }
        di = 0;
        for(dj = -1 ; dj <= 1 ; dj+=2){
            if(i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m && !visited[(i+di)*m+j+dj] && board[j+dj][i+di] == word[0]){
                if(word.length() == 1){return true;}
                visited[(i+di)*m+j+dj] = 1;
                exist |= dfs(board, word.substr(1, word.length() - 1), m, n, i+di, j+dj, visited);
                visited[(i+di)*m+j+dj] = 0;
            }
        }
        return exist;
    }
};
int main(){
    vector<vector<char> > board;
    board.push_back({'A','B','C','E'});
    board.push_back({'S','F','C','S'});
    board.push_back({'A','D','E','E'});
    return exist(board, "ABCCED");

}