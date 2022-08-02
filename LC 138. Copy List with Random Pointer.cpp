/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        unordered_map<Node*, Node*> m;
        Node* ret = new Node(head->val), *tmp = head->next;
        Node* tmp2 = ret;
        m[head] = tmp2;
        while(tmp){
            tmp2->next = new Node(tmp->val);
            tmp2 = tmp2->next;
            m[tmp] = tmp2;
            tmp = tmp->next;
        }
        Node* tmp3 = head, *tmp4 = ret;
        while(tmp3){
            tmp4->random = m[tmp3->random];
            tmp4 = tmp4->next;
            tmp3 = tmp3->next;
        }
        return ret;
    }
};
