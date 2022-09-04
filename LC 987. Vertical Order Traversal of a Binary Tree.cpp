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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root){
            return ret;
        }
        map<int,vector<int>> m;
        queue<int> q;
        queue<TreeNode*> qn;
        q.push(0);
        qn.push(root);
        while(!q.empty()){
            int n =q.size();
            map<int, vector<int>> tmpm;
            for(int i=0; i<n; i++){
                int tmp = q.front();
                TreeNode* tmp2 = qn.front();
                tmpm[tmp].push_back(tmp2->val);
                qn.pop();
                q.pop();
                if(tmp2->left){
                    q.push(tmp-1);
                    qn.push(tmp2->left);
                }
                if(tmp2->right){
                    q.push(tmp+1);
                    qn.push(tmp2->right);
                }
            }
            for(auto i:tmpm){
                vector<int> vtmp = i.second;
                sort(vtmp.begin(), vtmp.end());
                for(auto in:vtmp){
                    m[i.first].push_back(in);
                }
            }
            
        }
        for(auto i:m){
            vector<int> v2 = i.second;
            
            ret.push_back(v2);
        }
        return ret;
    }
};
