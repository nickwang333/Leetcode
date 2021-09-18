class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), tsum = 0;
        for(int i:nums){
            tsum ^= i;
        }
        return tsum;
    }
};
