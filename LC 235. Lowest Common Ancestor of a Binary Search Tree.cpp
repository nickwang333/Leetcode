/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> m;
        unordered_map<TreeNode*, int> m2;
        m[root] = NULL;
        queue<TreeNode*> q2;
        q2.push(root);
        while(!q2.empty()){
            TreeNode* tmp = q2.front();
            q2.pop();
            if(tmp->left){
                q2.push(tmp->left);
                m[tmp->left] = tmp;
            }
            if(tmp->right){
                q2.push(tmp->right);
                m[tmp->right] = tmp;
            }
        }
        TreeNode* tmp1 = p, *tmp2 = q;
        while(tmp1){
            m2[tmp1] = 1;
            tmp1 = m[tmp1];
        }
        while(tmp2){
            if(m2[tmp2] == 1){
                return tmp2;
            }
            tmp2 = m[tmp2];
        }
        return NULL;
    }
};
