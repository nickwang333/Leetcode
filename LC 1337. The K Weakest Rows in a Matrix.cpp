class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, vector<int>> m;
        for(int i=0; i<mat.size(); i++){
            int tmp = 0;
            for(int j:mat[i]){
                tmp += j;
            }
            m[tmp].push_back(i);
        }
        vector<int> ret;
        int counter = 0;
        for(auto i:m){
            if(counter == k){
                break;
            }
            for(int j:i.second){
                if(counter == k){
                    break;
                }
                ret.push_back(j);
                counter++;
            }
        }
        return ret;
    }
};
