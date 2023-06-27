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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        TreeNode* tmp1 = root1, *tmp2 = root2;
        unordered_map<int, int> m1, m2;
        queue<TreeNode*> q1, q2;
        q1.push(tmp1);
        q2.push(tmp2);
        while(!q1.empty()){
            tmp1 = q1.front();
            q1.pop();
            if(tmp1->left){
                q1.push(tmp1->left);
            }
            if(tmp1->right){
                q1.push(tmp1->right);
            }
            m1[tmp1->val] = 1;
        }
        while(!q2.empty()){
            tmp1 = q2.front();
            q2.pop();
            if(tmp1->left){
                q2.push(tmp1->left);
            }
            if(tmp1->right){
                q2.push(tmp1->right);
            }
            m2[tmp1->val] = 1;
        }
        for(auto i:m1){
            if(m2[target - i.first] == 1){
                return true;
            }
        }
        return false;
    }
};
