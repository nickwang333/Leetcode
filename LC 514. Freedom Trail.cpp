class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ret = key.size(), m = key.size(), n = ring.size();
        unordered_map<char, vector<int>> pos;
        vector<int> dp(n, -1);
        for(int i=0; i<n; i++){
            pos[ring[i]].push_back(i);
        }
        for(int i=0; i<m; i++){
            if(i == 0){
                for(int j:pos[key[i]]){
                    dp[j] = min(j, n-j);
                }
            }
            else{
                vector<int> tmp(n, -1);
                char prev = key[i-1];
                for(int j:pos[key[i]]){
                    for(int k:pos[prev]){
                        if(tmp[j] == -1){
                            tmp[j] = min(abs(j-k), abs(n-abs(j-k)));
                            tmp[j] += dp[k];
                        }
                        else{
                            int tmp2 = min(abs(j-k), abs(n-abs(j-k)));
                            tmp[j] = min(dp[k] + tmp2, tmp[j]);
                        }
                    }
                }
                dp = tmp;
            }
        }
        int mini = INT_MAX;
        for(auto i:pos[key[m-1]]){
            mini = min(mini, dp[i]);
        }
        return ret+mini;
    }
};
