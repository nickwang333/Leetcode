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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> v;
            while(!q.empty()){
                v.push_back(q.front());
                q.pop();
            }
            int first = 0, last = n-1;
            if(n == 1 && v[0]->left){
                swap(v[0]->left, v[0]->right);
                q.push(v[0]->left);
                q.push(v[0]->right);
            }
            else if(v[0]->left){
                while(first < last){
                    if(level%2 == 0){
                        swap(v[first]->left, v[last]->right);
                        swap(v[first]->right, v[last]->left);
                    }
                    else{
                        swap(v[first]->left, v[last]->left);
                        swap(v[first]->right, v[last]->right);
                    }
                    first++;
                    last--;
                }
                for(auto i:v){
                    q.push(i->left);
                    q.push(i->right);
                }
            }
            level++;
        }
        return root;
    }
};
