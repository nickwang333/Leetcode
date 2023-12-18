class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> v(2);
        unordered_map<int, int> m;
        for(auto i:grid){
            for(int j:i){
                m[j]++;
            }
        }
        for(int i=1; i<=grid.size()*grid.size(); i++){
            if(m[i] == 0){
                v[1] = i;    
            }
            else if(m[i] == 2){
                v[0] = i;
            }
        }
        return v;
    }
};
