class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long ret = 0, tmp = 0;
        int n = strategy.size();
        for(int i=0; i<n; i++){
            tmp += (prices[i] * strategy[i]);
        }
        ret = tmp;
        for(int i=0; i<n; i++){
            if(i < k/2){
                tmp -= (prices[i] * strategy[i]);
            }
            else if(i < k){
                tmp -= (prices[i] * strategy[i]);
                tmp += prices[i];
            }
            else{
                ret = max(ret, tmp);
                tmp += (prices[i-k] * strategy[i-k]);
                tmp -= (prices[i] * strategy[i]);
                tmp += prices[i];
                tmp -= (prices[i-k/2]);
            }
        }
        ret = max(ret, tmp);
        return ret;
    }
};
