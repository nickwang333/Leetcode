class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s, si;
        vector<int> ret = prices;
        for(int i=0; i<prices.size(); i++){
            while(!s.empty() && prices[i] <= s.top()){
                ret[si.top()] -= prices[i];
                s.pop();
                si.pop();
            }
            s.push(prices[i]);
            si.push(i);
        }
        return ret;
    }
};
