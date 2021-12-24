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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int counter = 0;
        vector<vector<int>> ret;
        TreeNode* tmp = root;
        queue<TreeNode*> s;
        s.push(tmp);
        if(!root){
            return ret;
        }
        while(!s.empty()){
            int n = s.size();
            vector<int> v(0);
            for(int i=0; i<n; i++){
                TreeNode* tmp2 = s.front();
                s.pop();
                v.push_back(tmp2->val);
                if(tmp2->left){
                    s.push(tmp2->left);
                }
                if(tmp2->right){
                    s.push(tmp2->right);
                }
            }
            if(counter%2==1){
                reverse(v.begin(), v.end());
            }
            ret.push_back(v);
            counter++;
        }
        return ret;
    }
};
