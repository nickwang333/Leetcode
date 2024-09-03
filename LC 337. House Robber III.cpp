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
    int rob(TreeNode* root) {
        int level = 0, ret = 0;
        queue<TreeNode*> q;
        unordered_map<int, vector<TreeNode*>> m;
        unordered_map<TreeNode*, int> dp;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                m[level].push_back(tmp);
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            level++;
        }
        for(int i=level-1; i>=0; i--){
            for(auto node:m[i]){
                int tmp1 = 0, tmp2 = node->val;
                if(node->left){
                    tmp1 += dp[node->left];
                    if(node->left->left){
                        tmp2 += dp[node->left->left];
                    }
                    if(node->left->right){
                        tmp2 += dp[node->left->right];
                    }
                }
                if(node->right){
                    tmp1 += dp[node->right];
                    if(node->right->left){
                        tmp2 += dp[node->right->left];
                    }
                    if(node->right->right){
                        tmp2 += dp[node->right->right];
                    }
                }
                dp[node] = max(tmp1, tmp2);
            }
        }
        return dp[root];
    }
};
