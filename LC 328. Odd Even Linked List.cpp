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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* tmp1 = head, *tmp2 = head->next, *tmp3 = tmp2;
        while(tmp1 && tmp2){
            tmp1->next = tmp2->next;
            if(tmp1->next){
                tmp1 = tmp1->next;
            }
            else{
                break;
            }
            if(tmp2->next){
                tmp2 ->next = tmp2->next->next;
                tmp2 = tmp2->next;
            }
        }
        tmp1->next = tmp3;
        return head;
    }
};
