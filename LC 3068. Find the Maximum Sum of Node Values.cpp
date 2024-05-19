class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ret = 0;
        priority_queue<int> pq;
        for(int i:nums){
            int tmp = (i^k) - i;
            ret += i;
            pq.push(tmp);
        }
        while(pq.size() > 1){
            int tmp1 = pq.top();
            pq.pop();
            int tmp2 = pq.top();
            pq.pop();
            if(tmp1+tmp2 > 0){
                ret += tmp1;
                ret += tmp2;
            }
        }
        return ret;
    }
};
