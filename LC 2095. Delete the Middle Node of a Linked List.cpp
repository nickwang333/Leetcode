/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next){
            return NULL;
        }
        ListNode* tmp1 = head, *tmp2 = head, *prev;
        while(tmp2){
            tmp2 = tmp2->next;
            if(tmp2 == NULL){//odd number of nodes
                prev->next = tmp1->next;
                return head;
            }
            if(tmp2->next == NULL){
                tmp1->next = tmp1->next->next;
                return head;
            }
            tmp2 = tmp2->next;
            prev = tmp1;
            tmp1 = tmp1->next;
        }
        return head;
    }
};
