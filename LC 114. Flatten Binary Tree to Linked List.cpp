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
    void preorder(TreeNode* root, queue<TreeNode*>& q){
        if(!root){
            return;
        }
        q.push(root);
        preorder(root->left, q);
        preorder(root->right, q);
    }
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        queue<TreeNode*> ret;
        preorder(root, ret);
        int n = ret.size();
        root->left = NULL;
        TreeNode* tmp = root;
        for(int i=0; i<n; i++){
            if(i==0){
                ret.pop();
            }
            else{
                tmp->right = new TreeNode(ret.front()->val);
                ret.pop();
                tmp = tmp->right;
            }
        }
    }
};
