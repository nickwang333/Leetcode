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
    int goodNodes(TreeNode* root) {
        queue<TreeNode*> qnode;
        queue<int> q;
        qnode.push(root);
        q.push(root->val);
        int ret = 0;
        while(!q.empty()){
            TreeNode* tmp = qnode.front();
            int tmpval = q.front();
            qnode.pop();
            q.pop();
            if(tmpval <= tmp->val){
                ret++;
            }
            if(tmp->left){
                qnode.push(tmp->left);
                q.push(max(tmp->val, tmpval));
            }
            if(tmp->right){
                qnode.push(tmp->right);
                q.push(max(tmp->val, tmpval));
            }
        }
        return ret;
    }
};
