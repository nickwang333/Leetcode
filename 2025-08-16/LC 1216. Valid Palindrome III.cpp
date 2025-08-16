class Solution {
public:
    int longestPalindromeSubseq(string& s) {
        int ret = 1, n = s.size();
        string sr = s;
        reverse(sr.begin(), sr.end());
        vector<int> dp(n+1, 0);
        for(int i=0; i<n; i++){
            vector<int> tmp = dp;
            for(int j=0; j<n; j++){
                if(s[i] == sr[j]){
                    tmp[j+1] = max(dp[j]+1, tmp[j+1]);
                    ret = max(ret, tmp[j+1]);
                }
                else{
                    tmp[j+1] = max(tmp[j], dp[j+1]);
                }
            }
            dp = tmp;
        }
        return ret;
    }

    bool isValidPalindrome(string s, int k) {
        int n = s.size(), len = longestPalindromeSubseq(s);
        return n-len <= k;
    }
};
