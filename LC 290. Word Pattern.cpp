class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n = pattern.size(), m = str.size(), len = (m+1)/n-1, j=0;
        map<char,string> mp;
        map<string,char> mp2;
        for(int i=0; i<n; i++){
            string tmp = "";
            if(j>=str.size()){
                return false;
            }
            while(j<str.size() && str[j]!=' '){
                tmp += str[j];
                j++;
            }
            j++;
            auto it = mp.find(pattern[i]);
            auto it2 = mp2.find(tmp);
            if(it==mp.end() && it2==mp2.end()){
                mp[pattern[i]] = tmp;
                mp2[tmp] = pattern[i];
            }
            else if(it!=mp.end() && it2!=mp2.end()){
                if(mp[pattern[i]]!=tmp || mp2[tmp]!=pattern[i]){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        if(j<str.size()){
            return false;
        }
        return true;
    }
};
