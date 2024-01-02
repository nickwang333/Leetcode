class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ret;
        unordered_map<int, int> m;
        int maxi = 0;
        for(int i:nums){
            m[i]++;
            maxi = max(maxi, m[i]);
        }
        for(int i=0; i<maxi; i++){
            vector<int> row;
            for(auto it=m.begin(); it!=m.end(); it++){
                if(it->second > 0){
                    it->second--;
                    row.push_back(it->first);
                }
            }
            ret.push_back(row);
        }
        return ret;
    }
};
