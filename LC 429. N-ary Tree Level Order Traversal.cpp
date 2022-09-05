/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if(!root){
            return ret;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> v(0);
            for(int i=0; i<n; i++){
                Node* tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                for(auto j:tmp->children){
                    q.push(j);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};
