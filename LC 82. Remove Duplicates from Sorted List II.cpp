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

//Second method that use constant extra space
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
        if(!head || !head->next){
            return head;
        }
        ListNode *ret = NULL, *tmp, *tmp1 = head, *tmp2 = head->next;
        int flag = 1;
        while(tmp2){
            if(tmp1->val != tmp2->val){
                if(flag == 1){
                    ListNode *tmp3 = new ListNode(tmp1->val);
                    ret = tmp3;
                    tmp = ret;
                    flag = 0;
                }
                else{
                    ListNode *tmp3 = new ListNode(tmp1->val);
                    tmp->next = tmp3;
                    tmp = tmp->next;
                }
                tmp2 = tmp2->next;
                tmp1 = tmp1->next;
                if(!tmp2){
                    if(flag == 1){
                        ListNode *tmp3 = new ListNode(tmp1->val);
                        ret = tmp3;
                        tmp = ret;
                        flag = 0;
                    }
                    else{
                        ListNode *tmp3 = new ListNode(tmp1->val);
                        tmp->next = tmp3;
                        tmp = tmp->next;
                    }
                }
            }
            else{
                while(tmp2 && tmp1->val==tmp2->val){
                    tmp1 = tmp1->next;
                    tmp2 = tmp2->next;
                }
                if(!tmp2){
                    return ret;
                }
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
                if(!tmp2){
                    if(flag == 1){
                        ListNode *tmp3 = new ListNode(tmp1->val);
                        ret = tmp3;
                        tmp = ret;;
                        flag = 0;
                    }
                    else{
                        ListNode *tmp3 = new ListNode(tmp1->val);
                        tmp->next = tmp3;
                        tmp = tmp->next;
                    }
                }
            }
        }
        return ret;
    }
};
