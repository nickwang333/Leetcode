class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> dp(target+1,0), tmp2;
        dp[0] = 1;
        vector<vector<int>> ret;
        vector<vector<vector<int>>> v(target+1);
        v[0].push_back(tmp2);
        for(int i:candidates){
            for(int j=0; j<=target-i; j++){
                dp[j+i]+=dp[j];
                for(int k=0; k<v[j].size(); k++){
                    vector<int> tmp = v[j][k];
                    tmp.push_back(i);
                    v[j+i].push_back(tmp);
                }
            }
        }
        ret = v[target];
        return ret;
    }
};
