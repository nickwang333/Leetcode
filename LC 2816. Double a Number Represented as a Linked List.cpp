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
    ListNode* reverse (ListNode* head){
        ListNode* curr = head, *next = NULL, *prev = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        ListNode* tmp = reverse(head), *ret = NULL, *tmp2 = NULL;
        int over = 0;
        while(tmp){
            if(!ret){
                ret = new ListNode((over + tmp->val * 2)%10);
                tmp2 = ret;
                over = (over + tmp->val * 2)/10;
            }
            else{
                tmp2->next = new ListNode((over + tmp->val * 2)%10);
                tmp2 = tmp2->next;
                over = (over + tmp->val * 2)/10;
            }
            tmp = tmp->next;
        }
        if(over != 0){
            tmp2->next = new ListNode(over);
        }
        ListNode* ret2 = reverse(ret);
        return ret2;
        
    }
};
