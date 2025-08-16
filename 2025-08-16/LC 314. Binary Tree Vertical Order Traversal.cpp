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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ret;
        unordered_map<int, vector<int>> m;
        queue<TreeNode*> q;
        queue<int> level;
        q.push(root);
        level.push(0);
        int mini = 0;
        int maxi = 0;
        if(!root){
            return ret;
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* tmp = q.front();
                q.pop();
                int tmp2 = level.front();
                level.pop();
                m[tmp2].push_back(tmp->val);
                if(tmp->left){
                    q.push(tmp->left);
                    level.push(tmp2-1);
                    mini = min(mini, tmp2-1);
                }
                if(tmp->right){
                    q.push(tmp->right);
                    level.push(tmp2+1);
                    maxi = max(maxi, tmp2+1);
                }
            }
        }
        for(int i=mini; i<=maxi; i++){
            ret.push_back(m[i]);
        }
        return ret;
    }
};
