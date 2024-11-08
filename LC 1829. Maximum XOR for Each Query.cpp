class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ret;
        int n = nums.size(), total = 0, maxi = pow(2, maximumBit) - 1;
        for(int i=0; i<n; i++){
            total ^= nums[i];
        }
        for(int i=n-1; i>=0; i--){
            if(i == n-1){
                ret.push_back(total ^ maxi);
            }
            else{
                total ^= nums[i+1];
                ret.push_back(total ^ maxi);
            }
        }
        return ret;
    }
};
