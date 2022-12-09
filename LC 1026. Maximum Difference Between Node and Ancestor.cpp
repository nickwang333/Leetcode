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
    int maxAncestorDiff(TreeNode* root) {
        int ret = 0;
        queue<int> qmin, qmax;
        queue<TreeNode*> q;
        q.push(root);
        qmin.push(root->val);
        qmax.push(root->val);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                int tmp1 = qmin.front();
                qmin.pop();
                int tmp2 = qmax.front();
                qmax.pop();
                if(!tmp){
                    continue;
                }
                if(tmp->left){
                    ret = max(ret, max(abs(tmp1-tmp->left->val),ret));
                    ret = max(ret, max(abs(tmp2-tmp->left->val),ret));
                    q.push(tmp->left);
                    qmin.push(min(tmp1, tmp->left->val));
                    qmax.push(max(tmp2, tmp->left->val));
                }
                if(tmp->right){
                    ret = max(ret, max(abs(tmp1-tmp->right->val),ret));
                    ret = max(ret, max(abs(tmp2-tmp->right->val),ret));
                    q.push(tmp->right);
                    qmin.push(min(tmp1, tmp->right->val));
                    qmax.push(max(tmp2, tmp->right->val));
                }
            }
        }
        return ret;
    }
};
