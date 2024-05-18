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

    int distributeCoins(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int, vector<TreeNode*>> level;
        unordered_map<TreeNode*, TreeNode*> parent;
        int level_no = 0, ret = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                level[level_no].push_back(tmp);
                q.pop();
                if(tmp->left){
                    q.push(tmp->left);
                    parent[tmp->left] = tmp;
                }
                if(tmp->right){
                    q.push(tmp->right);
                    parent[tmp->right] = tmp;
                }
            }
            level_no++;
        }
        unordered_map<TreeNode*, int> visited;
        for(int i=level_no-1; i>0; i--){
            for(TreeNode* j : level[i]){
                visited[j] = 1;
                if(j->val > 1){
                    parent[j]->val += (j->val-1);
                    ret += (j->val-1);
                    j->val = 1;
                }
                else if(j->val < 1){
                    parent[j]->val -= (1 - j->val);
                    ret += (1 - j->val);
                    j->val = 1;
                }
            }
        }
        return ret;
    }
};
