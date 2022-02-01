class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts[0].size(), ret = 0;
        vector<int> v(n,0);
        for(auto i:accounts){
            int tmp = 0;
            for(int j=0; j<i.size(); j++){
                tmp+=i[j];
            }
            ret = max(ret ,tmp);
        }
        return ret;
    }
};
