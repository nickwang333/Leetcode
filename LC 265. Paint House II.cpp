class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size(), min1, min2;
        priority_queue<int> q,q1;
        vector<int> v(k,0);
        vector<vector<int>> dp(n,v);
        for(int i=0; i<n; i++){
            if(i!=0){
                min1 = -q1.top();
                q1.pop();
                min2 = -q1.top();
            }
            for(int j=0; j<k; j++){
                if(i==0){
                    dp[i][j] = costs[i][j];
                    q.push(-costs[i][j]);
                }
                else{
                    if(dp[i-1][j] != min1){
                        dp[i][j] = min1+costs[i][j];
                    }
                    else{
                        dp[i][j] = min2+costs[i][j];
                    }
                    q.push(-dp[i][j]);
                }
            }
            q1 = q;
            while(!q.empty()){
                q.pop();
            }
        }
        return -q1.top();
    }
};
