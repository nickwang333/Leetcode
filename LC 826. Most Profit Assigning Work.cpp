class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>> v;
        for(int i=0; i<difficulty.size(); i++){
            vector<int> tmp{profit[i], difficulty[i]};
            v.push_back(tmp);
        }
        int ret = 0;
        sort(v.rbegin(), v.rend());
        for(int j:worker){
            for(int i=0; i<difficulty.size(); i++){
                if(v[i][1] <= j){
                    ret += v[i][0];
                    break;
                }
            }
        }
        return ret;
    }
};
