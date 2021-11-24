class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        int ret = 0;
        for(auto i:grid){
            for(int j:i){
                v.push_back(j);
            }
        }
        sort(v.begin(), v.end());
        int mid = v[v.size()/2];
        for(int i=0; i<v.size(); i++){
            if((abs(v[i]-mid))%x != 0){
                return -1;
            }
            ret += abs(v[i]-mid)/x;
        }
        return ret;
    }
};
