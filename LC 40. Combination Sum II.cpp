class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int,int> m;
        for(int i:candidates){
            m[i]++;
        }
        vector<int> dp(target+1, 0),tmp;
        dp[0] = 1;
        vector<vector<int>> ret;
        vector<vector<vector<int>>> v(target+1);
        v[0].push_back(tmp);
        for(auto it=m.begin(); it!=m.end(); it++){
            int i = it->first;
            for(int j=target-i; j>=0; j--){
                for(int z = 0; z<it->second; z++){
                    if((j+i*(z+1))<=target){
                        dp[j+i*(z+1)] += dp[j];
                        for(int k=0; k<v[j].size(); k++){
                            vector<int> tmp3 = v[j][k];
                            for(int a = 0; a<=z; a++){
                                tmp3.push_back(i);
                            }
                            v[j+i*(z+1)].push_back(tmp3);
                        }
                        
                    }
                }
            }
        }
        ret = v[target];
        
        return ret;
    }
};
