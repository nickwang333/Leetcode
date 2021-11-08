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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* ret = new TreeNode(val);
            return ret;
        }
        TreeNode* tmp = root;
        while(tmp!=NULL){
            if(tmp->val > val){
                if(tmp->left!=NULL){
                    tmp = tmp->left;
                }
                else{
                    TreeNode* ret = new TreeNode(val);
                    tmp->left = ret;
                    return root;
                }
            }
            else{
                if(tmp->right!=NULL){
                    tmp = tmp->right;
                }
                else{
                    TreeNode* ret = new TreeNode(val);
                    tmp->right = ret;
                    return root;
                }
            }
        }
        return root;
    }
};
