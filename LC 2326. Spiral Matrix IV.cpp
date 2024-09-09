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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int> row(n, -1);
        vector<vector<int>> ret(m, row);
        vector<int> dx{0,1,0,-1}, dy{1,0,-1,0};
        int d = 0, x = 0, y = 0;
        ret[0][0] = head->val;
        head = head->next;
        while(head){
            int tmpx = x + dx[d];
            int tmpy = y + dy[d];
            if(tmpx >= m || tmpx < 0 || tmpy >= n || tmpy < 0 || ret[tmpx][tmpy] != -1){
                d++;
                d %= 4;
                tmpx = x + dx[d];
                tmpy = y + dy[d];
            }
            ret[tmpx][tmpy] = head->val;
            x = tmpx;
            y = tmpy;
            head = head->next;
        }
        return ret;
    }
};
