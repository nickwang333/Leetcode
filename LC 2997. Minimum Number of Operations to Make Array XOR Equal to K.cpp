class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int total = 0, ret = 0;
        for(int i:nums){
            total ^= i;
        }
        int diff = total ^ k;
        while(diff > 0){
            ret += (diff % 2);
            diff /= 2;
        }
        return ret;
    }
};
