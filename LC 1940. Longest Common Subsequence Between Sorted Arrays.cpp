class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> ret;
        unordered_map<int, int> m;
        for(int i:arrays[0]){
            m[i]++;
        }
        int n = arrays.size();
        for(int i=1; i<n; i++){
            vector<int> tmp;
            unordered_map<int, int> m2;
            for(int j:arrays[i]){
                m2[j]++;
            }
            for(auto i:m){
                m[i.first] = min(m[i.first], m2[i.first]);
            }
        }
        for(auto i:m){
            for(int j=0; j<i.second; j++){
                ret.push_back(i.first);
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
