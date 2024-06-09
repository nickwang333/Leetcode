class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int total = 0;
        int ret = 0;
        m[total] = 1;
        for(int i:nums){
            total += i;
            total %= k;
            if (total < 0) {
                total += k;
            }
            ret += (m[total]);
            m[total]++;
        }
        return ret;
    }
};
