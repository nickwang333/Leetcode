class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int tsum = 0;
        vector<int> ret;
        for(int i:nums){
            if(i % 2 == 0){
                tsum += i;
            }
        }
        for(auto i:queries){
            if(nums[i[1]] % 2 == 0){
                tsum -= nums[i[1]];
            }
            if((nums[i[1]]+i[0])%2 == 0){
                tsum += (nums[i[1]]+i[0]);
            }
            nums[i[1]] += i[0];
            ret.push_back(tsum);
        }
        return ret;
    }
};
