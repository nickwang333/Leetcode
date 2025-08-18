/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* tmpp = p;
        Node* tmpq = q;
        while(tmpp || tmpq){
            if(tmpp->parent){
                tmpp = tmpp->parent;
            }
            else{
                tmpp = q;
            }
            if(tmpq->parent){
                tmpq = tmpq->parent;
            }
            else{
                tmpq = p;
            }
            if(tmpp == tmpq){
                return tmpp;
            }
        }
        return NULL;
    }
};
