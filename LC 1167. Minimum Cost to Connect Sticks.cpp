class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int> pq;
        for(int i:sticks){
            pq.push(-i);
        }
        int n = sticks.size(), ret = 0, prev = 0;
        while(pq.size()>1){
            prev = 0;
            prev = -pq.top();
            pq.pop();
            prev -= pq.top();
            pq.pop();
            ret += prev;
            pq.push(-prev);
        }
        return ret;
    }
};
