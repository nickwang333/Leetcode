class Solution {
public:
    bool check(int f[],int k){
        for(int i=0;i<26;i++)
            if(f[i]!=0 && f[i]<k) return 0;
        return 1;
    }
    int longestSubstring(string s, int k) {
        int ans{0};
        for(int i=0;i<s.length();i++){
             int f[26]={0};
            for(int j=i;j<s.length();j++){
                f[s[j]-'a']++; if(f[s[j]-'a']<k) continue;
                if(check(f,k)) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
