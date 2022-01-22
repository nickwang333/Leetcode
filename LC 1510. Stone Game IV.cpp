class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        vector<int > v;
        for(int i=1; i<=n; i++){
            if(i*i <= n){
                v.push_back(i*i);
            }
            else{
                break;
            }
        }
        for(int i=0; i<=n; i++){
            if(!dp[i]){
                for(int j:v){
                    if(j+i <= n){
                        dp[i+j] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};
