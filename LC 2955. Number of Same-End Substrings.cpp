class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        vector<int> ret;
        int n = s.size();
        // aaa: a, a, a, aa, aa, aaa
        vector<int> v(26, 0);
        vector<vector<int>> dp(n+1, v);
        for(int i=0; i<n; i++){
            v[s[i]-'a']++;
            dp[i+1] = v;
        }
        unordered_map<int, int> m;
        int tmp2 = 1;
        m[1] = 1;
        for(int i=2; i<=n; i++){
            m[i] = m[i-1]+i;
        }
        for(auto i:queries){
            vector<int> tmp(26, 0);
            int counter = 0;
            for(int j=0; j<26; j++){
                tmp[j] = dp[i[1]+1][j] - dp[i[0]][j];
                counter += m[tmp[j]];
            }
            ret.push_back(counter);
        }
        return ret;
    }
};
