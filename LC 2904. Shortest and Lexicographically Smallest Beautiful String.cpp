class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), len = n;
        vector<int> pos;
        vector<string> ret;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                pos.push_back(i);
            }
        }
        if(pos.size() < k){
            return "";
        }
        for(int i=0; i<pos.size()-k+1; i++){
            len = min(len, pos[i+k-1] - pos[i] + 1);
        }
        string ret2;
        for(int i=0; i<pos.size()-k+1; i++){
            if(len == pos[i+k-1] - pos[i] + 1){
                if(ret2 == ""){
                    ret2 = s.substr(pos[i], len);
                }
                else{
                    string tmp = s.substr(pos[i], len);
                    if(tmp < ret2){
                        ret2 = tmp;
                    }
                }
            }
        }
        return ret2;
    }
};
