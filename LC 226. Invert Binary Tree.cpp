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
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left && tmp->right){
                    TreeNode* tmp2 = tmp->left;
                    tmp->left = tmp->right;
                    tmp->right = tmp2;
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
                else if(tmp->left){
                    tmp->right = tmp->left;
                    tmp->left = NULL;
                    q.push(tmp->right);
                }
                else if(tmp->right){
                    tmp->left = tmp->right;
                    tmp->right = NULL;
                    q.push(tmp->left);
                }
                
            }
        }
        return root;
    }
};
