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
    int computeGCD(int a, int b){
        for(int i=min(a,b); i>0; i--){
            if(a%i == 0 && b%i == 0){
                return i;
            }
        }
        return 1;
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* tmp1 = head, *tmp2 = head->next;
        while(tmp2){
            ListNode* tmp3 = tmp2->next;
            tmp1->next = new ListNode(computeGCD(tmp1->val, tmp2->val), tmp2);
            tmp1 = tmp2;
            tmp2 = tmp3;
        }
        return head;
    }
};
