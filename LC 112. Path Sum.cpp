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
    bool hasPathSum(TreeNode* root, int targetSum) {
        queue<int> q1;
        queue<TreeNode*> q2;
        if(!root){
            return false;
        }
        q1.push(root->val);
        q2.push(root);
        while(!q1.empty()){
            int tmp = q1.front();
            q1.pop();
            TreeNode* tmp2 = q2.front();
            q2.pop();
            if(!tmp2->left && !tmp2->right){
                if(tmp == targetSum){
                    return true;
                }
            }
            if(tmp2->left){
                q2.push(tmp2->left);
                q1.push(tmp+tmp2->left->val);
            }
            if(tmp2->right){
                q2.push(tmp2->right);
                q1.push(tmp+tmp2->right->val);
            }
        }
        return false;
    }
};
