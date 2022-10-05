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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        q.push(root);
        if(depth == 1){
            TreeNode* ret = new TreeNode(val);
            ret->left = root;
            return ret;
        }
        int level = 2;
        while(!q.empty()){
            int n = q.size();
            cout << n;
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(level == depth){
                    tmp->left = new TreeNode(val, tmp->left, NULL);
                    tmp->right = new TreeNode(val, NULL, tmp->right);
                }
                else{
                    if(tmp->left){
                        q.push(tmp->left);
                    }
                    if(tmp->right){
                        q.push(tmp->right);
                    }
                }
            }
            level++;
        }
        return root;
    }
};
