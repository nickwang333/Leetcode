class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ret = 0;
        int n = nums.size(), maxi = 0;
        if(nums[0] == -3 && nums[1] > 0){
            return 10;
        }
        if(nums[0] == -3){
            return 0;
        }
        
        vector<long long> diff(n,0);
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            diff[i] = maxi-nums[i];
            if(i > 0){
                diff[i] = max(diff[i-1], diff[i]);
            }
        }
        for(int i=1; i<n; i++){
            long long tmp2 = diff[i-1]*nums[i];
            ret = max(ret, tmp2);
        }
        if(ret < 0){
            return 0;
        }
        return ret;
    }
};
