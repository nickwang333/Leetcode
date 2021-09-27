class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = 0, reset = 0, hold = -prices[0];
        for(int i=1; i<prices.size(); i++){
            int tmp = sell;
            sell = hold+prices[i];
            hold = max(hold, reset-prices[i]);
            reset = max(tmp, reset);
        }
        return max(reset, sell);
    }
};
