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
bool same_tree(TreeNode* t1, TreeNode* t2){
    if(t1==NULL || t2==NULL){
        return t1==t2;
    }
    return (t1->val == t2->val && same_tree(t1->left, t2->left) && same_tree(t1->right, t2->right));
}

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode* tmp = root;
        stack<TreeNode*> s;
        if(tmp){
            s.push(tmp);
        }
        while(!s.empty()){
            TreeNode* tmp2 = s.top();
            TreeNode* tmp3 = subRoot;
            s.pop();
            if(tmp2->right){
                s.push(tmp2->right);
            }
            if(tmp2->left){
                s.push(tmp2->left);
            }
            if(same_tree(tmp2, tmp3)){
                return true;
            }
    }
        return false;
    }
};
