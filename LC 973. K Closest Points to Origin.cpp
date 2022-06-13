class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ret;
        map<int, vector<vector<int>>> m;
        for(auto i:points){
            int tmp = i[0]*i[0] + i[1]*i[1];
            m[tmp].push_back(i);
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            if(k == 0){
                break;
            }
            for(int i=0; i<it->second.size(); i++){
                ret.push_back(it->second[i]);
                k--;
            }
        }
        return ret;
    }
};
