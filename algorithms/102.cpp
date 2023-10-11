/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > vec_res;
        vector<vector<int> > vec_left;
        vector<vector<int> > vec_right;
        if(root == NULL) return vec_res;
        vector<int> root_vec = {root->val};
        if(root->left != NULL)
            vec_left = levelOrder(root->left);
        if(root->right != NULL)
            vec_right = levelOrder(root->right);
        int append_len = min(vec_left.size(), vec_right.size());
        int max_len = max(vec_left.size(), vec_right.size());
        bool flg = vec_left.size() >= vec_right.size();
        vec_res.emplace_back(vector<int>());
        vec_res[0].emplace_back(root->val);
        for(int i = 1 ; i <= append_len ; i++){
            vec_res.emplace_back(vector<int>());
            vec_res[i].insert(vec_res[i].end(), vec_left[i-1].begin(), vec_left[i-1].end());
            vec_res[i].insert(vec_res[i].end(), vec_right[i-1].begin(), vec_right[i-1].end());

        }
        for(int i = append_len + 1; i <= max_len ; i++){
            if(flg){
                vec_res.emplace_back(vec_left[i-1]);
            }
            else{
                vec_res.emplace_back(vec_right[i-1]);
            }
        }
        return vec_res;
    }
};

// solution 1:930ms && 290.4MB

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > vec_left;
        vector<vector<int> > vec_right;
        if(root == NULL) return vector<vector<int> >();
        vector<int> root_vec = {root->val};
        if(root->left != NULL)
            vec_left = levelOrder(root->left);
        if(root->right != NULL)
            vec_right = levelOrder(root->right);
        int left_size = vec_left.size();
        int right_size = vec_right.size();
        if(left_size >= right_size){
            vec_left.emplace(vec_left.begin(), root_vec);
            for(int i = 0 ; i < right_size; i ++){
                vec_left[i+1].insert(vec_left[i+1].end(), vec_right[i].begin(), vec_right[i].end());
            }
            return vec_left;
        }
        else{
            vec_right.emplace(vec_right.begin(), root_vec);
            for(int i = 0 ; i < left_size; i ++){
                vec_right[i+1].insert(vec_right[i+1].begin(), vec_left[i].begin(), vec_left[i].end());
            }
            return vec_right;
        }
    }
};

//solution2: 158ms && 20.3MB

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > vec_res;
        if(root == NULL) return vec_res;
        queue<TreeNode*> node_q;
        node_q.push(root);
        while(!node_q.empty()){
            int len = node_q.size();
            vector<int> tmp_res;
            for(int i = 0 ; i < len ; i++){
                TreeNode* cur_node = node_q.front();
                node_q.pop();
                if(cur_node->left != NULL)
                    node_q.push(cur_node->left);
                if(cur_node->right != NULL)
                    node_q.push(cur_node->right);
                tmp_res.push_back(cur_node->val);
            }
            vec_res.push_back(tmp_res);
        }
        return vec_res;
    }
};

//solution3: 0ms && 13.6MB