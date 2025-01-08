class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2){
        if(str2.size() < str1.size()){
            return false;
        }
        int m = str1.size(), n = str2.size();
        return (str1 == str2.substr(0, m)) && (str1 == str2.substr(n-m));
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ret = 0, n = words.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    ret++;
                }
            }
        }
        return ret;
    }
};
