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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root){
            return ret;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> v(0);
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};
