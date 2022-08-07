class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ret = 0;
        unordered_map<int,int> m;
        for(int i:nums){
            m[i] = 1;
        }
        for(int i=0; i<nums.size(); i++){
            if(m[nums[i]+diff] == 1 && m[nums[i]+2*diff] == 1){
                ret++;
            }
        }
        return ret;
    }
};
