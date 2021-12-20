class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<long long> v(n,1);
        long long ret = 1;
        for(int i=1; i<n; i++){
            if(prices[i]+1 == prices[i-1]){
                v[i] = v[i-1]+1;
                ret += v[i];
            }
            else{
                ret++;
            }
        }
        return ret;
    }
};
