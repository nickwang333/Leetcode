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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tmp = list1, *tmp2;
        for(int i=1; i<a; i++){
            tmp = tmp->next;
        }
        tmp2 = tmp->next;
        for(int i=0; i<=b-a; i++){
            tmp2 = tmp2->next;
        }
        tmp->next = list2;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = tmp2;
        return list1;
    }
};
