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
        if(!root){
            return 0;
        }
        int ret = 0;
        TreeNode* tmp = root;
        queue<int> q;
        queue<TreeNode*> qn;
        qn.push(tmp);
        q.push(tmp->val);
        while(!qn.empty()){
            int n = qn.size();
            for(int i=0; i<n; i++){
                TreeNode* tmp2 = qn.front();
                qn.pop();
                int tmp3 = q.front();
                q.pop();
                if(tmp2->left){
                    int tmp4 = tmp3*10+tmp2->left->val;
                    q.push(tmp4);
                    qn.push(tmp2->left);
                }
                if(tmp2->right){
                    int tmp4 = tmp3*10+tmp2->right->val;
                    q.push(tmp4);
                    qn.push(tmp2->right);
                }
                if(!tmp2->left && !tmp2->right){
                    ret += tmp3;
                }
            }
        }
        return ret;
    }
};
