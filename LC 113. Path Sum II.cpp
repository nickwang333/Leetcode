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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        if(root == NULL){
            return ret;
        }
        queue<int> q;
        queue<TreeNode*> qn;
        queue<vector<int>> qv;
        q.push(root->val);
        qn.push(root);
        vector<int> tmp{root->val};
        qv.push(tmp);
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                int tmpq = q.front();
                q.pop();
                TreeNode* tmpqn = qn.front();
                qn.pop();
                vector<int> tmpqv = qv.front();
                qv.pop();
                if(tmpqn->left){
                    qn.push(tmpqn->left);
                    q.push(tmpq+tmpqn->left->val);
                    vector<int> tmpv1 = tmpqv;
                    tmpv1.push_back(tmpqn->left->val);
                    qv.push(tmpv1);
                }
                if(tmpqn->right){
                    qn.push(tmpqn->right);
                    q.push(tmpq+tmpqn->right->val);
                    vector<int> tmpv2 = tmpqv;
                    tmpv2.push_back(tmpqn->right->val);
                    qv.push(tmpv2);
                }
                if(!tmpqn->right && !tmpqn->left && tmpq == targetSum){
                    ret.push_back(tmpqv);
                }
            }
        }
        return ret;
    }
};
