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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ret = NULL, *tmp1 = headA, *tmp2 = headB;
        int a = 0, b = 0, flag = 1;
        while(tmp1){
            tmp1 = tmp1->next;
            a++;
        }
        while(tmp2){
            tmp2 = tmp2->next;
            b++;
        }
        tmp1 = headA; 
        tmp2 = headB;
        if(a>b){
            for(int i=0; i<a-b; i++){
                tmp1 = tmp1->next;
            }
        }
        else{
            for(int i=0; i<b-a; i++){
                tmp2 = tmp2->next;
            }
        }
        while(tmp1){
            if(tmp1 == tmp2 && flag==1){
                cout << tmp1->val;
                ret = tmp1;
                flag = 0;
            }
            else if(tmp1->val != tmp2->val ){
                ret = NULL;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return ret;
    }
};
