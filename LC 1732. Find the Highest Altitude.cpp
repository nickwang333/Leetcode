class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ret = 0, tsum = 0;
        for(int i:gain){
            tsum += i;
            ret = max(ret, tsum);
        }
        return ret;
    }
};
