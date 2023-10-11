#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
using namespace std;
struct node {
    map<int, node*> next;
    int flg;
    node() {
        flg = 0;
    }
};

void insert(const char *str, node *root) {
    node *p = root; 
    int i = 0, index; 
    while (str[i]) {
        index = str[i] - 'a'; 
        if (p -> next.find(index) == p -> next.end())
            p -> next.insert(make_pair(index, new node()));
        p = p -> next[index]; 
        i++;
    }
    p->flg = 1;
}

int search(node * root, string word){
    int i = 0, index;
    const char * str = word.c_str();
    node * p = root;
    int cnt = 0;
    while (str[i]){
        index = str[i] - 'a';
        if (p -> next.find(index) == p -> next.end()){
            return 0x7fffffff;
        }
        else if (p -> next[index] -> flg == 1){
            return cnt;
        }
        else{  
            p = p -> next[index];
            cnt++;
        }
        i++;
    }
    return 0x7fffffff;
    
}

void search_first(node * root, int min_forbidden, string word, int & m){
    int length = word.length();
    for(int i = 0 ; i < length ; i++){
        if(i == 0){
            int pos = search(root, word.substr(length - i - 1, i + 1));
            min_forbidden = min(1, pos);
        }
        else{
            int pos = search(root, word.substr(length - i - 1, i + 1));
            min_forbidden = min(pos, min_forbidden + 1);
            cout<<min_forbidden<<endl;
        }
        m = max(m, min_forbidden);
    }
}

int longestValidSubstring(string word, vector<string>& forbidden) {
    node * tree_root = new node();
    int length = forbidden.size();
    for(int i = 0 ; i < length ; i++){
        insert(forbidden[i].c_str(), tree_root);
    }
    int word_length = word.length();
    int min_forbidden = 0x7fffffff;
    int m = 0;
    search_first(tree_root, min_forbidden, word, m);
    return m;
}
int main(){
    string a = "cbaaaabc";
    vector<string> b = {"aaa","cb"};
    cout<<longestValidSubstring(a,b)<<endl;
}