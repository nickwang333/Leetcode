class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size(), ret = 1;
        vector<int> dp(n,1), dp2(n,2);
        map<char, int> m;
        for(char i:text){
            m[i]++;
        }
        if(n>=2){
            if(text[0]==text[1]){
                dp[1] = 2;
                dp2[1] = 3;
                ret = 2;
            }
        }
        for(int i=2; i<n; i++){
            if(text[i]==text[i-1]){
                dp[i]+=dp[i-1];
                dp2[i]=dp2[i-1]+1;
            }
            else if(text[i]==text[i-2]){
                dp2[i] += dp[i-2];
            }
            if(ret < dp2[i]){
                ret = dp2[i];
                if(ret > m[text[i]]){
                    ret = m[text[i]];
                }
            }
        }
        for(int i=0; i<dp.size(); i++){
            if(ret<dp2[i]){
                ret = dp2[i];
                if(ret > m[text[i]]){
                    ret = m[text[i]];
                }
            }
        }
        for(int i=0; i<dp.size(); i++){
            cout << dp[i] << " " << dp2[i] << endl;
        }
        return ret;
    }
};
