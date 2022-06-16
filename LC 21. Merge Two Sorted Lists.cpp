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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ret = NULL, *tmp1 = list1, *tmp2 = list2, *tmpr;
        if(list1 == NULL && list2 == NULL){
            return ret;
        }
        else if(list2 == NULL){
            return list1;
        }
        else if(list1 == NULL){
            return list2;
        }
        else if(list1->val > list2->val){
            ret = new ListNode(list2->val);
            tmpr = ret;
            tmp2 = tmp2->next;
        }
        else{
            ret = new ListNode(list1->val);
            tmpr = ret;
            tmp1 = tmp1->next;
        }
        while(tmp1 || tmp2){
            if(tmp1 == NULL){
                tmpr->next = new ListNode(tmp2->val);
                tmp2 = tmp2->next;
                tmpr = tmpr->next;
            }
            else if(tmp2 == NULL){
                tmpr->next = new ListNode(tmp1->val);
                tmp1 = tmp1->next;
                tmpr = tmpr->next;
            }
            else{
                if(tmp1->val > tmp2->val){
                    tmpr->next = new ListNode(tmp2->val);
                    tmp2 = tmp2->next;
                    tmpr = tmpr->next; 
                }
                else{
                    tmpr->next = new ListNode(tmp1->val);
                    tmp1 = tmp1->next;
                    tmpr = tmpr->next;
                }
            }
        }
        return ret;
    }
};
