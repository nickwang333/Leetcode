/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }
        ListNode* tmp1 = head, *tmp2 = head;
        while(tmp2 && tmp2->next){
            tmp2 = tmp2->next->next;
            tmp1 = tmp1->next;
            if(tmp1 == tmp2){
                return true;
            }
        }
        return false;
    }
};
