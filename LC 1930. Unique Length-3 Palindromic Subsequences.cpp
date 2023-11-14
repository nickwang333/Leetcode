class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ret = 0;
        unordered_map<char, vector<int>> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]].push_back(i);
        }
        for(auto i:m){
            if(i.second.size() >= 2){
                int sz = i.second.size();
                int begin = i.second[0], end = i.second[sz-1];
                map<char, int> m2;
                for(int j=begin+1; j<end; j++){
                    m2[s[j]] = 1;
                }
                ret += m2.size();
            }
        }
        return ret;
    }
};
