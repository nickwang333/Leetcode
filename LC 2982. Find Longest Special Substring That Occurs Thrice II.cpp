class Solution {
public:
    int maximumLength(string s) {
        int ret = -1, begin = 0;
        unordered_map<string, int> m;
        char tmp = s[0];
        for(int i=1; i<s.size(); i++){
            if(s[i] != s[i-1]){
                string tmp2(i-begin, tmp);
                begin = i;
                tmp = s[i];
                m[tmp2]++;
            }
        }
        string tmp2(s.size()-begin, tmp);
        m[tmp2]++;
        
        for(auto it:m){
            cout << it.first << " " << it.second << endl;
            int tmp2 = it.first.size();
            if(it.second > 2){
                ret = max(ret, tmp2);
            }
            if(it.first.size() >= 3){
                ret = max(ret, tmp2-2);
            }
            string tmp3 = it.first.substr(0, it.first.size()-1);
            auto it2 = m.find(tmp3);
            if((it2 != m.end() && m[tmp3] == 1) || it.second > 1){
                ret = max(ret, tmp2-1);
            }
        }
        if(ret == 0){
            return -1;
        }
        return ret;
    }
};
