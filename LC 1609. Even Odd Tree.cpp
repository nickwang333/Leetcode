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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = -1;
        while(!q.empty()){
            int n = q.size();
            int prev = -1;
            level++;
            for(int i=0; i<n; i++){
                TreeNode* tmp = q.front();
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
                q.pop();
                if(level % 2 == 0){
                    if(prev == -1){
                        prev = tmp->val;
                        if(prev % 2 != 1){
                            return false;
                        }
                    }
                    else{
                        if(tmp->val % 2 != 1 || tmp->val <= prev){
                            return false;
                        }
                        prev = tmp->val;
                    }
                }
                else{
                    if(prev == -1){
                        prev = tmp->val;
                        if(prev % 2 == 1){
                            return false;
                        }
                    }
                    else{
                        if(tmp->val % 2 == 1 || tmp->val >= prev){
                            return false;
                        }
                        prev = tmp->val;
                    }
                }
            }
        }
        return true;
    }
};
