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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, int> visited;
        int ret = 0;
        TreeNode* startn = new TreeNode();
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q, q2;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->val == start){
                startn = tmp;
                visited[tmp] = 1;
                q2.push(tmp);
            }
            if(tmp->left){
                parent[tmp->left] = tmp;
                q.push(tmp->left);
            }
            if(tmp->right){
                parent[tmp->right] = tmp;
                q.push(tmp->right);
            }
        }
        while(!q2.empty()){
            int sz = q2.size();
            for(int i=0; i<sz; i++){
                TreeNode* tmp = q2.front();
                q2.pop();
                if(parent[tmp] && visited[parent[tmp]] == 0){
                    q2.push(parent[tmp]);
                    visited[parent[tmp]] = 1;
                }
                if(tmp->left && visited[tmp->left] == 0){
                    q2.push(tmp->left);
                    visited[tmp->left] = 1;
                }                
                if(tmp->right && visited[tmp->right] == 0){
                    q2.push(tmp->right);
                    visited[tmp->right] = 1;
                }
            }
            ret++;
        }
        return ret-1;
    }
};
