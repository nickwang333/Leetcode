class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], ret=0;
        for(int i:prices){
            ret = max(ret, i-mini);
            mini = min(mini, i);
        }
        return ret;
    }
};
