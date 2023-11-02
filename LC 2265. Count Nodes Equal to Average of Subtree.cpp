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
    int averageOfSubtree(TreeNode* root) {
        int ret = 0, counter = 0;
        unordered_map<TreeNode*, TreeNode*> parents;
        unordered_map<int, vector<TreeNode*>> level;
        unordered_map<TreeNode*, int> tsum, tcount;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                level[counter].push_back(tmp);
                q.pop();
                if(tmp->left){
                    q.push(tmp->left);
                    parents[tmp->left] = tmp;
                }
                if(tmp->right){
                    q.push(tmp->right);
                    parents[tmp->right] = tmp;
                }
            }
            counter++;
        }
        for(int i=counter-1; i>=0; i--){
            for(auto j:level[i]){
                if(j->left){
                    tcount[j] += tcount[j->left];
                    tsum[j] += tsum[j->left];
                }
                if(j->right){
                    tcount[j] += tcount[j->right];
                    tsum[j] += tsum[j->right];
                }
                tsum[j] += j->val;
                tcount[j]++;
                if(tsum[j] / tcount[j] == j->val){
                    ret++;
                }
            }
        }
        return ret;
    }
};
