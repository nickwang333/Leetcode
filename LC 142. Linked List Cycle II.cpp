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
    ListNode *detectCycle(ListNode *head) {
        int flag = 1, way  = 0;
        ListNode* tmp1 = head, *tmp2 = head, *tmp3 = head;
        while(tmp2 && tmp2->next){
            tmp2 = tmp2->next;
            tmp2 = tmp2->next;
            tmp1 = tmp1->next;
            if(tmp1==tmp2){
                break;
            }
        }
        if(!tmp2 || !tmp2->next || !tmp2->next->next){
            return NULL;
        }
        while(tmp1){
            if(tmp1==tmp3){
                return tmp1;
            }
            tmp1 = tmp1->next;
            tmp3 = tmp3->next;
        }
        return NULL;
    }
};
