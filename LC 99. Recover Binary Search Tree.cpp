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
    void inorder(TreeNode* root, vector<TreeNode*>& v){
        if(!root){
            return;
        }
        inorder(root->left, v);
        if(root){
           v.push_back(root); 
        }
        inorder(root->right, v);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);
        TreeNode* tmp = NULL, *tmp2 = NULL;
        int n = v.size();
        for(int i=0; i<n; i++){
            if(!tmp && i != n-1 && v[i]->val > v[i+1]->val){
                tmp = v[i];
            }
            if(i != 0 && tmp && v[i]->val < v[i-1]->val){
                tmp2 = v[i];
            }
        }
        int tmp1 = tmp2->val;
        tmp2->val = tmp->val;
        tmp->val = tmp1;
        
    }
};
