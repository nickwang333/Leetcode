class Solution {
public:
    int maximumLength(string s) {
        int ret = -1, begin = 0;
        unordered_map<string, int> m;
        string tmp;
        tmp += s[0];
        m[tmp] = 1;
        for(int i=1; i<s.size(); i++){
            if(s[i] == s[i-1]){
                tmp = s.substr(begin, i-begin+1);
                m[tmp]++;
            }
            else{
                tmp = "";
                tmp += s[i];
                begin = i;
                m[tmp]++;
            }
        }
        
        for(auto it:m){
            //cout << it.first << " " << it.second << endl;
            int tmp2 = it.first.size();
            if(it.second > 2){
                ret = max(ret, tmp2);
            }
            if(it.first.size() >= 3){
                ret = max(ret, tmp2-2);
            }
            string tmp3 = it.first.substr(0, it.first.size()-1);
            auto it2 = m.find(tmp3);
            if(it2 != m.end() && m[tmp3] >= 2){
                ret = max(ret, tmp2-1);
            }
        }
        return ret;
    }
};
