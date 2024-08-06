class Solution {
public:
    int longestRepeatingSubstring(string s) {
        vector<int> v;
        int ret = 0, n = s.size();
        unordered_map<string, int> m;
        for(int i=0; i<n; i++){
            string tmp;
            tmp += s[i];
            m[tmp]++;
            if(m[tmp] > 1){
                int tmp2 = tmp.size();
                ret = max(ret, tmp2);
            }
            for(int j=i+1; j<n; j++){
                tmp += s[j];
                m[tmp]++;
                if(m[tmp] > 1){
                    int tmp2 = tmp.size();
                    ret = max(ret, tmp2);
                }
            }
        }
        return ret;
    }
};
