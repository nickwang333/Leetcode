class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ret = 0, tmp = 0;
        vector<int> v(102, 0);
        for(auto i:nums){
            v[i[0]]++;
            v[i[1]+1]--;
        }
        for(auto i:v){
            tmp += i;
            (tmp > 0) ? ret++: ret;
        }
        return ret;
    }
};
