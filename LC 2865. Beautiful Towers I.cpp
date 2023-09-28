class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ret = 0;
        int n = maxHeights.size();
        vector<long long> dp(n, 0), dp2(n, 0);
        stack<int> s, s2, spos, s2pos;
        for(int i=0; i<n; i++){
            while(!s.empty() && s.top() > maxHeights[i]){
                s.pop();
                spos.pop();
            }
            if(s.empty()){
                dp[i] = (long long)maxHeights[i] * (i+1);
            }
            else{
                dp[i] = dp[spos.top()] + (long long)(i-spos.top()) * (long long)maxHeights[i];
            }
            s.push(maxHeights[i]);
            spos.push(i);
        }
        reverse(maxHeights.begin(), maxHeights.end());
        for(int i=0; i<n; i++){
            while(!s2.empty() && s2.top() > maxHeights[i]){
                s2.pop();
                s2pos.pop();
            }
            if(s2.empty()){
                dp2[i] = (long long)maxHeights[i] * (i+1);
            }
            else{
                dp2[i] = dp2[s2pos.top()] + (long long)(i-s2pos.top()) * (long long)maxHeights[i];
            }
            s2.push(maxHeights[i]);
            s2pos.push(i);
        }
        reverse(dp2.begin(), dp2.end());
        ret = dp[n-1];
        for(int i=0; i<n-1; i++){
            ret = max(ret, dp[i] + dp2[i+1]);
        }
        ret = max(ret, dp2[0]);
        return ret;
    }
};
