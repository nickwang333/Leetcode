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
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        ListNode* tmp = head, *tmp2 = head, *ret = NULL, *tmp3;
        while(tmp){
            v.push_back(tmp->val);
            tmp = tmp->next;
        }
        int tmpval = v[v.size()-1];
        for(int i=v.size()-1; i>=0 ;i--){
            tmpval = max(v[i], tmpval);
            v[i] = tmpval;
        }
        int counter = 0;
        while(tmp2){
            if(tmp2->val >= v[counter]){
                if(ret == NULL){
                    ret = tmp2;
                    tmp3 = ret;
                }
                else{
                    tmp3->next = tmp2;
                    tmp3 = tmp3->next;
                }
            }
            tmp2 = tmp2->next;
            counter++;
        }
        return ret;
    }
};
