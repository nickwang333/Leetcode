class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int, int> m;
        for(auto i:lights){
            m[i[0]-i[1]]++;
            m[i[0]+i[1]+1]--;
        }
        int total = 0, ret = 0, maxi = 0;
        for(auto it:m){
            total += it.second;
            if(total > maxi){
                maxi = total;
                ret = it.first;
            }
        }
        return ret;
    }
};
