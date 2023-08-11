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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tmp = head, *curr = NULL, *prev = NULL, *next = NULL, *end = NULL;
        for(int i=1; i<left; i++){
            prev = tmp;
            tmp = tmp->next;
            end = tmp;
        }
        ListNode* head2 = prev;
        prev = NULL;
        for(int i=left; i<=right; i++){
            next = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = next;
        }
        if(left != 1){
            end->next = next;
            head2->next = prev;
        }
        else{
            head->next = next;
            return prev;
        }
        return head;
    }
};
