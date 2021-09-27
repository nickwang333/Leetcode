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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, flag = 1;
        ListNode* tmp1 = l1, *tmp2 = l2, *ret = new ListNode, *tmp3 = ret;
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        while(tmp1!=NULL || tmp2!=NULL){
            if(tmp1 == NULL){
                int tmpint = tmp2->val;
                tmp2 = tmp2->next;
                int digit = (tmpint+carry)%10;
                carry = (tmpint+carry)/10;
                ListNode* tmp = new ListNode(digit);
                tmp3->next = tmp;
                tmp3 = tmp3->next;
            }
            else if(tmp2 == NULL){
                int tmpint = tmp1->val;
                tmp1 = tmp1->next;
                int digit = (tmpint+carry)%10;
                carry = (tmpint+carry)/10;
                ListNode* tmp = new ListNode(digit);
                tmp3->next = tmp;
                tmp3 = tmp3->next;
            }
            else{
                int tmpint = tmp1->val + tmp2->val;
                int digit = (tmpint+carry)%10;
                carry = (tmpint+carry)/10;
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
                if(flag==1){
                    ListNode* tmp = new ListNode(digit);
                    ret = tmp;
                    tmp3 = ret;
                    flag = 0;
                }
                else{
                    ListNode* tmp = new ListNode(digit);
                    tmp3->next = tmp;
                    tmp3 = tmp3->next;
                }
            }
        }
        if(carry == 1){
            ListNode* tmp = new ListNode(carry);
            tmp3->next = tmp;
        }
        return ret;
    }
};
