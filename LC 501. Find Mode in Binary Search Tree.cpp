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
    vector<int> findMode(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ret;
        unordered_map<int, int> m;
        int maxi = 0;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            m[tmp->val]++;
            maxi = max(maxi, m[tmp->val]);
            q.pop();
            if(tmp->left){
                q.push(tmp->left);
            }
            if(tmp->right){
                q.push(tmp->right);
            }
        }
        for(auto i:m){
            if(i.second == maxi){
                ret.push_back(i.first);
            }
        }
        return ret;
    }
};
