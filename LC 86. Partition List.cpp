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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = NULL, *head2 = NULL, *tmp1 = head, *tmp2 = NULL, *tmp3 = NULL;
        while(tmp1){
            if(tmp1->val >= x){
                if(!head2){
                    head2 = new ListNode(tmp1->val);
                    tmp2 = head2;
                }
                else{
                    tmp2->next = new ListNode(tmp1->val);
                    tmp2 = tmp2->next;
                }
                tmp1 = tmp1->next;
            }
            else{
                if(!head1){
                    head1 = new ListNode(tmp1->val);
                    tmp3 = head1;
                }
                else{
                    tmp3->next = new ListNode(tmp1->val);
                    tmp3 = tmp3->next;
                }
                tmp1 = tmp1->next;
            }
        }
        if(tmp3){
            tmp3->next = head2;
            return head1;
        }
        else{
            return head2;
        }
    }
};
