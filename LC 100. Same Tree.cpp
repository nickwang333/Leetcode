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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q){
            if(!p && !q){
                return true;
            }
            return false;
        }
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty()){
            int n = q1.size();
            for(int i=0; i<n; i++){
                
                TreeNode* tmp1 = q1.front();
                TreeNode* tmp2 = q2.front();
                q1.pop();
                q2.pop();
                if(tmp1->val != tmp2->val){
                    return false;
                }
                if(tmp1->left){
                    if(!tmp2->left){
                        return false;
                    }
                    q1.push(tmp1->left);
                    q2.push(tmp2->left);
                }
                else if(tmp2->left){
                    return false;
                }
                if(tmp1->right){
                    if(!tmp2->right){
                        return false;
                    }
                    q1.push(tmp1->right);
                    q2.push(tmp2->right);
                }
                else if(tmp2->right){
                    return false;
                }
            }
        }
        return true;
    }
};
