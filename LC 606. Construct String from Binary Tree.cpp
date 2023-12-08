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
    void inorder(TreeNode* root, string& s){
        s = s + to_string(root->val);
        if(root->left){
            s = s + '(';
            inorder(root->left, s);
            s = s + ')';
        }
        if(!root->left && root->right){
            s = s + "()(";
            inorder(root->right, s);
            s = s + ')';
        }
        else if(root->right){
            s = s + '(';
            inorder(root->right, s);
            s = s + ')';
        }
    }
public:
    string tree2str(TreeNode* root) {
        string ret;
        inorder(root, ret);
        return ret;
    }
};
