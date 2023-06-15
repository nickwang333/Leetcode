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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int tsum = root->val, ret = 1, counter = 1;
        while(!q.empty()){
            int n = q.size();
            int tmpv = 0;
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
                tmpv += tmp->val;
            }
            if(tmpv > tsum){
                ret = counter;
                tsum = tmpv;
            }
            cout << tmpv << " ";
            counter++;
        }
        return ret;
    }
};
