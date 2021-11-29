class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n = nums.size(), tsum = 0;
        vector<int> ret(n, -1);
        for(int i=0; i<n && i<2*k; i++){
            tsum += nums[i];
        }
        for(int i=k; i<n-k; i++){
            tsum += nums[i+k];
            if(i!=k){
                tsum -= nums[i-k-1];
            }
            ret[i] = (tsum/(2*k+1));
        }
        return ret;
    }
};
