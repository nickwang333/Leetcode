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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> m;
        if(!head || !head->next){
            return head;
        }
        ListNode* ret = head, *tmp = head, *tmp2 = ret;
        while(tmp){
            m[tmp->val]++;
            tmp = tmp->next;
        }
        int flag = 0;
        for(auto it = m.begin(); it!=m.end(); it++){
            if(it->second == 1){
                ListNode* curr = new ListNode(it->first);
                if(flag == 0){
                    flag = 1;
                    ret = curr;
                }
                tmp2->next = curr;
                tmp2 = tmp2->next;
            }
        }
        if(flag == 0){
            return NULL;
        }
        return ret;
    }
};
