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
        TreeNode* ret;
        unordered_map<TreeNode*, TreeNode*> m;
        unordered_map<TreeNode*, int> m2;
        queue<TreeNode*> q1;
        q1.push(root);
        while(!q1.empty()){
            TreeNode* tmp = q1.front();
            q1.pop();
            if(tmp->left){
                q1.push(tmp->left);
                m[tmp->left] = tmp;
            }
            if(tmp->right){
                q1.push(tmp->right);
                m[tmp->right] = tmp;
            }
        }
        TreeNode* tmp = p, *tmp2 = q;
        m2[p] = 1;
        while(tmp){
            tmp = m[tmp];
            m2[tmp] = 1;
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
