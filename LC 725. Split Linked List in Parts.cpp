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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ret(k, NULL);
        if(!head){
            return ret;
        }
        ret[0] = head;
        ListNode* tmp = head;
        int sz = 0;
        while(tmp){
            sz++;
            tmp = tmp->next;
        }
        tmp = head;
        int tmp_sz = sz / k + (sz%k == 0 ? 0:1), counter = 1, index = 1;
        while(tmp){
            ListNode* next = tmp->next;
            if(counter >= tmp_sz){
                tmp->next = NULL;
                if(index < ret.size()){
                    ret[index] = next;
                }
                tmp = next;
                counter = 1;
                sz -= tmp_sz;
                k--;
                if(k != 0){
                    tmp_sz = sz / k + (sz%k == 0 ? 0:1);
                }
                
                index++;
            }
            else{
                counter++;
                tmp = tmp->next;
            }
            if(!tmp){
                break;
            }
        }
        return ret;
    }
};
