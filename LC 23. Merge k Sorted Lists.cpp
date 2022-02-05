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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = NULL, *tmp = ret;
        int flag = 1;
        priority_queue<int> q;
        for(auto i:lists){
            while(i){
                q.push(-i->val);
                i = i->next;
            }
        }
        while(!q.empty()){
            int i = -q.top();
            q.pop();
            if(flag == 1){
                flag = 0;
                ret = new ListNode(i);
                tmp = ret;
            }
            else{
                tmp->next = new ListNode(i);
                tmp = tmp->next;
            }
        }
        return ret;
    }
};
