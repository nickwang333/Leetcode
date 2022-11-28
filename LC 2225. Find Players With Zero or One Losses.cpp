class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> m;
        for(auto i:matches){
            m[i[0]];
            m[i[1]]++;
        }
        vector<int> v1, v2;
        for(auto i:m){
            if(i.second == 1){
                v2.push_back(i.first);
            }
            else if(i.second == 0){
                v1.push_back(i.first);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        vector<vector<int>> ret{v1,v2};
        return ret;
    }
};
