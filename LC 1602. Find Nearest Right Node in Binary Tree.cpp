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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        TreeNode* tmp = root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* tmp2 = q.front();
                q.pop();
                if(tmp2 == u){
                    if(i==n-1){
                        return NULL;
                    }
                    return q.front();
                }
                if(tmp2->left){
                    q.push(tmp2->left);
                }
                if(tmp2->right){
                    q.push(tmp2->right);
                }
            }
        }
        return NULL;
    }
};
