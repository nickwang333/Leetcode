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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ret = 0;
        TreeNode* tmp = root;
        queue<TreeNode*> q;
        q.push(tmp);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                tmp = q.front();
                q.pop();
                if(tmp->val>= low && tmp->val<=high){
                    ret += tmp->val;
                    if(tmp->left){
                        q.push(tmp->left);
                    }
                    if(tmp->right){
                        q.push(tmp->right);
                    }
                }
                else if(tmp->val > high){
                    if(tmp->left){
                        q.push(tmp->left);
                    }
                }
                else if(tmp->val < low){
                    if(tmp->right){
                        q.push(tmp->right);
                    }
                }
            }
        }
        return ret;
    }
};
