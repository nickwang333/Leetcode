bool comp(string s1, string s2){
    return s1.size()<s2.size();
}
    
bool is_pre(string& s1, string& s2){
    if(s1.size() == s2.size()+1){
        for(int i=0; i<s2.size(); i++){
            if(s1[i]!=s2[i]){
                return s1.substr(i+1)==s2.substr(i);
            }
        }
        return true;
    }
    return false;
}

class Solution {
    
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(), ret = 1;
        vector<int> dp(n,1);
        sort (words.begin(), words.end(), comp);
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(words[i].size() > words[j].size()+1){
                    break;
                }
                if(is_pre(words[i], words[j])){
                    dp[i] = max(dp[i], dp[j]+1);
                    ret = max(ret, dp[i]);
                }
            }
        }
        return ret;
    }
};
