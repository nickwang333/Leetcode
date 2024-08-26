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
private:
    vector<int> v;
public:
    void post(Node* root){
        if(root){
            for(Node* i : root->children){
                post(i);
                v.push_back(i->val);
            }
        }
    }
    vector<int> postorder(Node* root) {
        post(root);
        if(root){
            v.push_back(root->val);
        }
        return v;
    }
};
