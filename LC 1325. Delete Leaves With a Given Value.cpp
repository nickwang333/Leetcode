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
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        queue<TreeNode*> q;
        q.push(root);
        int level_no = 0;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<int, vector<TreeNode*>> level;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                level[level_no].push_back(tmp);
                if(tmp->left){
                    parent[tmp->left] = tmp;
                    q.push(tmp->left);
                }
                if(tmp->right){
                    parent[tmp->right] = tmp;
                    q.push(tmp->right);
                }
            }  
            level_no++;
        }
        for(int i=level_no-1; i>=0; i--){
            for(auto j:level[i]){
                if(!j->left && !j->right && j->val == target){
                    if(j == root){
                        return NULL;
                    }
                    if(parent[j]->left == j){
                        parent[j]->left = NULL;
                    }
                    else{
                        parent[j]->right = NULL;
                    }
                }
            }
        }
        return root;
    }
};
