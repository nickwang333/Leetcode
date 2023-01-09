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
    void preOrder(vector<int>& v, TreeNode* root){
        if(!root){
            return;
        }
        v.push_back(root->val);
        if(root->left){
            preOrder(v, root->left);
        }
        if(root->right){
            preOrder(v, root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preOrder(ret, root);
        return ret;
    }
};
