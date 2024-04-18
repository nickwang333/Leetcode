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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ret;
        map<TreeNode*, vector<TreeNode*>> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left){
                q.push(tmp->left);
                parent[tmp].push_back(tmp->left);
            }
            if(tmp->right){
                q.push(tmp->right);
                parent[tmp].push_back(tmp->right);
            }
        }
        for(auto i:parent){
            if(i.second.size() == 1){
                ret.push_back(i.second[0]->val);
            }
        }
        return ret;
    }
};
