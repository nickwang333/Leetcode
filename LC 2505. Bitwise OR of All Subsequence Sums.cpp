class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        long long ret = 0, total = 0;
        for(int i:nums){
            total += i;
            ret |= total;
            ret |= i;
        }
        
        return ret;
    }
};
