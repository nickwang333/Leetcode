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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> m;
        for(int i:nums){
            m[i] = 1;
        }
        ListNode* tmp = head, *ret = NULL, *tmp2 = ret;
        while(tmp){
            if(m[tmp->val] == 1){
                tmp = tmp->next;
                if(tmp2 != NULL){
                    tmp2->next = NULL;
                }
                continue;
            }
            else{
                if(ret == NULL){
                    ret = tmp;
                    tmp2 = ret;
                }
                else{
                    tmp2->next = tmp;
                    tmp2 = tmp2->next;
                }
            }
            tmp = tmp->next;
        }
        return ret;
    }
};
