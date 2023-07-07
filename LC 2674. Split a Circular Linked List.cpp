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
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        vector<ListNode*> ret{list};
        int n = 1;
        unordered_map<ListNode*, int> m;
        ListNode* tail = NULL, *mid = list;
        queue<ListNode*> q;
        q.push(list);
        while(1){
            ListNode* tmp = q.front();
            q.pop();
            if(!tail && m[tmp->next] == 1){
                tail = tmp;
            }
            if(m[tmp] == 1){
                break;
            }
            m[tmp] = 1;
            q.push(tmp->next);
            n++;
        }
        for(int i=1; i<n/2; i++){
            mid = mid->next;
        }
        tail->next = mid->next;
        ret.push_back(mid->next);
        mid->next = list;
        return ret;
    }
};
