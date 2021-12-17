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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i=0;
        ListNode* tmp = head, *prev;
        vector<int> ret(2,-1),v;
        while(tmp->next){
            prev = tmp;
            tmp = tmp->next;
            if(tmp->next){
                if((tmp->val<prev->val && tmp->val<tmp->next->val) || tmp->val>prev->val && tmp->val>tmp->next->val){
                    v.push_back(i);
                }
            }
            i++;
        }
        int n = v.size();
        if(v.size()<2){
            return ret;
        }
        ret[1] = v[n-1]-v[0];
        int mini = v[1]-v[0];
        for(int j=1; j<n; j++){
            mini = min(mini, v[j]-v[j-1]);
        }
        ret[0] = mini;
        return ret;
    }
};
