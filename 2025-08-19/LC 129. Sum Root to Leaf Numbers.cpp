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
    int sumNumbers(TreeNode* root) {
        int ret = 0;
        if(!root){
            return 0;
        }
        queue<TreeNode*> q;
        queue<int> q2;
        q.push(root);
        q2.push(root->val);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                int tmp2 = q2.front();
                q2.pop();
                if(tmp->left){
                    q.push(tmp->left);
                    q2.push(tmp2*10 + tmp->left->val);
                }
                if(tmp->right){
                    q.push(tmp->right);
                    q2.push(tmp2*10 + tmp->right->val);
                }
                if(!tmp->right && !tmp->left){
                    ret += tmp2;
                }
            }
        }
        return ret;
    }
};
