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
    int getMinimumDifference(TreeNode* root) {
        map<int, int> m;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            if(tmp){
                m[tmp->val]++;
            }
            q.pop();
            if(tmp->left){
                q.push(tmp->left);
            }
            if(tmp->right){
                q.push(tmp->right);
            }
        }
        int prev = -1, ret = INT_MAX;
        for(auto i:m){
            if(i.second > 1){
                return 0;
            }
            if(prev == -1){
                prev = i.first;
            }
            else{
                ret = min(ret, i.first-prev);
                prev = i.first;
            }
        }
        return ret;
    }
};
