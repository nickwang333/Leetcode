class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> m;
        vector<string> ret;
        for(string i:cpdomains){
            int tmp = 0;
            string tmps = "";
            vector<string> tmpv{};
            for(char j:i){
                if(isdigit(j)){
                    int tmp_digit = j-'0';
                    tmp = tmp*10 + tmp_digit;
                }
                else if(j == ' '){
                    continue;
                }
                else if(j == '.'){
                    tmpv.push_back(tmps);
                    tmps = "";
                }
                else{
                    tmps += j;
                }
            }
            tmpv.push_back(tmps);
            tmps = "";
            for(int j=tmpv.size()-1; j>=0; j--){
                if(tmps == ""){
                    tmps += tmpv[j];
                }
                else{
                    string tmpss = tmpv[j];
                    tmpss += '.';
                    tmpss += tmps;
                    tmps = tmpss;
                }
                m[tmps] += tmp;
            }
        }
        for(auto it = m.begin(); it != m.end(); it++){
            string tmp1 = to_string(it->second);
            tmp1 += ' ';
            tmp1 += it->first;
            ret.push_back(tmp1);
        }
        return ret;
    }
};
