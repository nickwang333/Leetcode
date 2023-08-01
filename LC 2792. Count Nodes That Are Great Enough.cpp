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
    int countGreatEnoughNodes(TreeNode* root, int k) {
        queue<TreeNode*> q, q2;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, int> visited;
        unordered_map<TreeNode*, priority_queue<int>> values;
        unordered_map<TreeNode*, vector<TreeNode*>> children;
        unordered_map<int, vector<TreeNode*>> level;
        q.push(root);
        int ret = 0, count = 0;
        parent[root] = NULL;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* tmp = q.front();
                q.pop();
                level[count].push_back(tmp);
                if(tmp->left){
                    q.push(tmp->left);
                    parent[tmp->left] = tmp;
                    children[tmp].push_back(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                    parent[tmp->right] = tmp;
                    children[tmp].push_back(tmp->right);
                }
                if(!tmp->left && !tmp->right){
                    priority_queue<int> tmpq;
                    values[tmp] = tmpq;
                }
            }
            count++;
        }
        count--;
        for(auto i:level[count]){
            q2.push(i);
        }
        while(!q2.empty()){
            int sz = q2.size();
            for(int i=0; i<sz; i++){
                TreeNode* tmp = q2.front();
                q2.pop();
                TreeNode* tmp_parent = parent[tmp];
                if(visited[tmp_parent] == 0  && tmp_parent != NULL){
                    visited[tmp_parent] = 1;
                    priority_queue<int> pq1;
                    q2.push(tmp_parent);
                    for(auto i1:children[tmp_parent]){
                        pq1.push(-i1->val);
                        priority_queue<int> pq4 = values[i1];
                        while(!pq4.empty()){
                            pq1.push(pq4.top());
                            pq4.pop();
                        }
                    }
                    if(pq1.size() > k){
                        priority_queue<int> pq2;
                        for(int j=0; j<k; j++){
                            pq2.push(pq1.top());
                            pq1.pop();
                        }
                        pq1 = pq2;
                    }
                    int large = 0;
                    values[tmp_parent] = pq1;
                    priority_queue<int> pq3 = pq1;
                    while(!pq3.empty()){
                        large = pq3.top();
                        pq3.pop();
                    }
                    if(-large < tmp_parent->val && pq1.size() >= k){
                        ret++;
                    }
                }
            }
            for(auto i:level[count-1]){
                if(visited[i] == 0){
                    q2.push(i);
                    visited[i] = 1;
                }
            }
            count--;
        }
        return ret;
        
    }
};
