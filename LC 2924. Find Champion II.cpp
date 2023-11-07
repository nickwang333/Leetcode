class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> v(n, true);
        int count = 0, ret = -1;
        for(auto i:edges){
            v[i[1]] = false;
        }
        for(int i=0; i<n; i++){
            if(v[i]){
                count++;
                ret = i;
            }
        }
        if(count != 1){
            return -1;
        }
        return ret;
    }
};
