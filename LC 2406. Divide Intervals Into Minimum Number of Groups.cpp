class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int maxi = 1, ret = 0, tmp = 0;
        for(auto i:intervals){
            maxi = max(maxi, i[1]);
        }
        vector<int> v(maxi+2, 0);
        for(auto i:intervals){
            v[i[0]]++;
            v[i[1]+1]--;
        }
        for(int i:v){
            tmp+=i;
            ret = max(ret, tmp);
        }
        return ret;
    }
};
