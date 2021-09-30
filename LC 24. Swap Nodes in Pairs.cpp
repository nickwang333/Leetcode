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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *dummy= new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;

        while(head && head->next){
            ListNode* firstNode = head;
            ListNode* secondNode = head->next;

            // Swapping
            prev->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;

            // Reinitializing the head and prevNode for next swap
            prev = firstNode;
            head = firstNode->next; 
        }
        return dummy->next;
    }
};
