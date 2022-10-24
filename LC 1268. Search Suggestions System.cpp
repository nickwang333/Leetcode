class Solution{
public:    
    vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
        vector<vector<string>> ret;
        sort(A.begin(), A.end());
        auto it = A.begin();
        string tmp = "";
        for(char i:searchWord){
            vector<string> v;
            tmp += i;
            it = lower_bound(it, A.end(), tmp);
            for(int j=0; j<3 && it+j != A.end(); j++){
                string tmp3 = *(it+j);
                if(tmp3.find(tmp)) break;
                v.push_back(tmp3);
            }
            ret.push_back(v);
        }
        return ret;
    }
};
