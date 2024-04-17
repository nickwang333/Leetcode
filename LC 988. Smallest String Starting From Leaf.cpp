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
    string smallestFromLeaf(TreeNode* root) {
        string ret = "";
        queue<string> qString;
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> leaves;
        unordered_map<TreeNode*, TreeNode*> parent;
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left){
                q.push(tmp->left);
                parent[tmp->left] = tmp;
            }
            if(tmp->right){
                q.push(tmp->right);
                parent[tmp->right] = tmp;
            }
            if(!tmp->left && !tmp->right){
                leaves.push_back(tmp);
            }
        }
        int mini = 25;
        for(auto i:leaves){
            mini = min(mini, i->val);
        }
        for(auto i:leaves){
            if(i->val == mini){
                q.push(i);
                char tmp = 'a' + i->val;
                string tmps = "";
                tmps += tmp;
                qString.push(tmps);
            }
        }
        while(!q.empty()){
            TreeNode* tmp = q.front();
            string tmps = qString.front();
            q.pop();
            qString.pop();
            TreeNode* tmpParent = parent[tmp];
            if(tmpParent){
                q.push(tmpParent);
                char tmp = 'a' + tmpParent->val;
                tmps += tmp;
                qString.push(tmps);
            }
            else{
                if(ret == ""){
                    ret = tmps;
                }
                else if(tmps < ret){
                    ret = tmps;
                }
            }
        }
        return ret;
    }
};
