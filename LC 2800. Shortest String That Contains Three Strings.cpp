class Solution {
    string common(string a, string b){
        string ret = a;
        int m = a.size(), n = b.size();
        if(m > n){
            for(int i=0; i<m; i++){
                if((i+n) <= m && a.substr(i, n) == b){
                    return a;
                }
            }
        }
        else{
            for(int i=0; i<n; i++){
                if((i+m) <= n && b.substr(i, n) == a){
                    return b;
                }
            }
        }
        for(int i=0; i<m; i++){
            int sz = a.size() - i;
            if(sz <= n && a.substr(i) == b.substr(0,sz)){
                ret += b.substr(sz);
                return ret;
            }
        }
        ret += b;
        return ret;
    }
public:
    string minimumString(string a, string b, string c) {
        // abc acb bac bca cab cba
        string tmp1 = common(a,b);
        string tmp2 = common(a,c);
        string tmp3 = common(b,c);
        // bca abc abc cab
        string tmp4 = common(tmp3,a);
        string tmp5 = common(common(c,b), a);
        string tmp6 = common(tmp1,c);
        string tmp7 = common(c,tmp1);
        string tmp8 = common(tmp2,b);
        string tmp9 = common(b,tmp2);
        vector<string> rets{tmp4,tmp5,tmp6,tmp7,tmp8,tmp9};
        sort(rets.begin(), rets.end());
        string ret = rets[0];
        for(auto i:rets){
            if(i.size() < ret.size()){
                ret = i;
            }
        }
        return ret;
    }
};
                     
                     
                     
                     
                     
                     
