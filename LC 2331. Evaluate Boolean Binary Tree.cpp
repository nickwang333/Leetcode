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
    bool evaluateTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int, vector<TreeNode*>> l;
        unordered_map<TreeNode*, int> val;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                val[tmp] = tmp->val;
                if(tmp->left){
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
                l[level].push_back(tmp);
            }
            level++;
        }
        
        for(int i=level-1; i>=0; i--){
            for(auto j:l[i]){
                if(j->val == 3){
                    val[j] = val[j->left] && val[j->right];
                }
                else if(j->val == 2){
                    val[j] = val[j->left] || val[j->right];
                }
            }
        }

        if(val[root] == 1){
            return true;
        }
        return false;
    }
};
