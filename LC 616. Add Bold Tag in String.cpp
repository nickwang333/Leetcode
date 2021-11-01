class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        string ret;
        int n = s.size(), conti = 0, end = -1;
        vector<int> v(n+1,0);
        for(int i=0; i<s.size(); i++){
            for(auto j:words){
                if(i+j.size()<=n){
                    if(s.substr(i, j.size())==j){
                        v[i] += 1;
                        v[i+j.size()] -= 1;
                    }
                }
            }
        }
        int tmp = 0;
        for(int i:v){
            cout << i << " ";
        }
        for(int i=0; i<=n; i++){
            if(tmp==0 && tmp+v[i]>0){
                ret += "<b>";
            }
            else if(tmp>0 && tmp+v[i]<=0){
                ret += "</b>";
            }
            tmp += v[i];
            if(i!=n){
                ret += s[i];
            }
        }
        return ret;
    }
};
