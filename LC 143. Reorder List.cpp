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
    void reorderList(ListNode* head) {
        if(!head || !head->next){return;}
        ListNode* fp = head, *sp= head;
        while(fp && fp->next){
            fp = fp->next->next;
            sp = sp->next;
        }
        fp = head;
        ListNode* prev = NULL, *next = NULL;
        while(sp){
            next = sp->next;
            sp->next = prev;
            prev = sp;
            sp = next;
        }
        sp = prev;
        ListNode* next_fp = NULL, *next_sp = NULL;
        while(fp->next && sp->next){
            next_fp = fp->next;
            next_sp = sp->next;
            fp->next = sp;
            sp->next = next_fp;
            fp = next_fp;
            sp = next_sp;
        }
    }
};
