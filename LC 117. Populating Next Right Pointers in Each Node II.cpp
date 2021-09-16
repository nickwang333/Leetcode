/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* head = NULL, *cur = root, *prev = NULL;
        while(cur){
            while(cur){
                if(cur->left){
                    if(!head){
                        head = cur->left;
                    }
                    if(!prev){
                        prev = cur->left;
                    }
                    else{
                        prev->next = cur->left;
                        prev = prev->next;
                    }
                }
                if(cur->right){
                    if(!head){
                        head = cur->right;
                    }
                    if(!prev){
                        prev = cur->right;
                    }
                    else{
                        prev->next = cur->right;
                        prev = prev->next;
                    }
                }
                cur = cur->next;
            }
            cur = head;
            head = NULL;
            prev = NULL;
        }
        return root;
    }
};
