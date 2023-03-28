class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, 0);

        int smallest = min(costs[0], min(costs[1], costs[2]));
        dp[1] = smallest;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + smallest;
        }

        for(int i=0; i<n; i++){
            dp[i+1] = min(dp[i+1], dp[i]+smallest);
            
            for(int j=i+1; j<n; j++){
                if(days[j] - days[i] < 7){
                    dp[j+1] = min(dp[j+1], dp[j] + costs[0]);
                    dp[j+1] = min(dp[j+1], dp[i] + costs[1]);
                }
                else if( days[j] - days[i] < 30){
                    dp[j+1] = min(dp[j+1], dp[j] + costs[0]);
                    dp[j+1] = min(dp[j+1], dp[i] + costs[2]);
                }
            }
        }

        for(int i:dp){
            cout << i << " ";
        }
        return dp[n];
    }
};
