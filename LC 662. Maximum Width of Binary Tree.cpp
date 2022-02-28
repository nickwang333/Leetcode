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
    int widthOfBinaryTree(TreeNode* root) {
        queue<long> q;
        queue<TreeNode*> qr;
        q.push(0);
        qr.push(root);
        long ret = 1;
        while(!q.empty()){
            long n = q.size(), tmp1 = 0, tmp2 = 0, de = 0;
            for(int i=0; i<n; i++){
                if(i==0){
                    de = q.front();
                    tmp1 = de;
                }
                TreeNode* node = qr.front();
                qr.pop();
                long tmp = q.front();
                q.pop();
                if(node->left){
                    qr.push(node->left);
                    q.push((tmp-de)*2);
                }
                if(node->right){
                    qr.push(node->right);
                    q.push((tmp-de)*2+1);
                }
                if(i == n-1){
                    tmp2 = tmp;
                }
            }
            if(n == 1){
                ret = max(ret, long(1));
            }
            else{
                ret = max(ret, tmp2-tmp1+1);
            }
        }
        return ret;
    }
};
