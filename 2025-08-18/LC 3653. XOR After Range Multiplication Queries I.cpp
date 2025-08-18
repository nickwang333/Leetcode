class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1000000007;
        for(auto query:queries){
            for(int i=query[0]; i<=query[1]; i+=query[2]){
                nums[i] = long(nums[i])*long(query[3]) % mod;
            }
        }
        int ret = 0;
        for(int i:nums){
            ret ^= i;
        }
        return ret;
    }
};
