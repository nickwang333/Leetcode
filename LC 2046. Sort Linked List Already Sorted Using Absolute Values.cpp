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
    ListNode* sortLinkedList(ListNode* head) {
        ListNode* tmp = head, *posi = NULL, *nega = NULL, *posi_tmp, *nega_tmp;
        while(tmp){
            if(tmp->val >= 0){
                if(!posi){
                    posi = new ListNode(tmp->val);
                    posi_tmp = posi;
                }
                else{
                    posi_tmp->next = new ListNode(tmp->val);
                    posi_tmp = posi_tmp->next;
                }
            }
            else{
                if(!nega){
                    nega = new ListNode(tmp->val);
                    nega_tmp = nega;
                }
                else{
                    nega_tmp->next = new ListNode(tmp->val);
                    nega_tmp = nega_tmp->next;
                }
            }
            tmp = tmp->next;
        }
        ListNode* prev = posi, *curr = nega, *next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        nega = prev;
        return nega;
    }
};
