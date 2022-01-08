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
    int pairSum(ListNode* head) {
        ListNode* tmp = head;
        vector<int> v;
        while(tmp){
            v.push_back(tmp->val);
            tmp = tmp->next;
        }
        int ret = 0;
        int fp = 0, sp = v.size()-1;
        while(fp<=sp){
            ret = max(ret, v[fp]+v[sp]);
            fp++;
            sp--;
        }
        return ret;
    }
};
