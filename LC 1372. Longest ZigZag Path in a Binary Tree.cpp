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
    int longestZigZag(TreeNode* root) {
        int ret = 0;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> ml, mr;
        q.push(root);
        ml[root] = 0;
        mr[root] = 0;
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left){
                q.push(tmp->left);
                int tmpl = ml[tmp];
                mr[tmp->left] = tmpl+1;
                ret = max(ret, tmpl+1);
            }
            if(tmp->right){
                q.push(tmp->right);
                int tmpr = mr[tmp];
                ml[tmp->right] = tmpr+1;
                ret = max(ret, tmpr+1);
            }
        }
        return ret;
    }
};
