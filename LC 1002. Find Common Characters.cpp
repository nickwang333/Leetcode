class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v(26, INT_MAX);
        int n = words.size();
        for(int i=0; i<n; i++){
            vector<int> v2(26, 0);
            for(char j:words[i]){
                v2[j-'a']++;
            }
            for(int j=0; j<26; j++){
                v[j] = min(v[j], v2[j]);
            }
        }
        vector<string> ret;
        for(int i=0; i<26; i++){
            for(int j=0; j<v[i]; j++){
                string tmp = "";
                tmp += ('a' + i);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};
