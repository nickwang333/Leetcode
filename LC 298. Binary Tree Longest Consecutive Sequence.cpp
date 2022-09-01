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
    int longestConsecutive(TreeNode* root) {
        int ret = 1;
        queue<TreeNode*> qNode;
        queue<int> q;
        qNode.push(root);
        q.push(1);
        while(!q.empty()){
            TreeNode* tmp = qNode.front();
            int tmpq = q.front();
            ret = max(tmpq, ret);
            qNode.pop();
            q.pop();
            if(tmp->left){
                if(tmp->val+1 == tmp->left->val){
                    q.push(tmpq+1);
                }
                else{
                    q.push(1);
                }
                qNode.push(tmp->left);
            }
            if(tmp->right){
                if(tmp->val+1 == tmp->right->val){
                    q.push(tmpq+1);
                }
                else{
                    q.push(1);
                }
                qNode.push(tmp->right);
            }
        }
        return ret;
    }
};
