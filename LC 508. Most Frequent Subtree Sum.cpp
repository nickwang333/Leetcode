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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> m;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ret;
        
        vector<vector<TreeNode*>> v2;
        
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> tmpv(0);
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                tmpv.push_back(tmp);
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            v2.push_back(tmpv);
        }
        
        int n = v2.size();
        
        for(int i = n-1; i >= 0; i--){
            for(int j=0; j<v2[i].size(); j++){
                TreeNode* tmpt = v2[i][j];
                if(tmpt->left){
                    tmpt->val += tmpt->left->val;
                }
                if(tmpt->right){
                    tmpt->val += tmpt->right->val;
                }
                m[tmpt->val]++;
            }
        }
        int maxi = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            maxi = max(it->second, maxi);
        }
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second == maxi){
                ret.push_back(it->first);
            }
        }       
        return ret;
    }
};
