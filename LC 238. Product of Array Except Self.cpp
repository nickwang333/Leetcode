class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tsum = 1, num_0 = 0, n = nums.size();
        vector<int> ret(n);
        for(int i:nums){
            if(i!=0){
                tsum*=i;
            }
            else{
                num_0++;
            }
        }
        if(num_0>1){
            for(int i=0; i<n; i++){
                ret[i] = 0;
            }
        }
        else if(num_0==1){
            for(int i=0; i<n; i++){
                if(nums[i]==0){
                    ret[i] = tsum;
                }
                else{
                    ret[i] = 0;
                }
            }
        }
        else{
            for(int i=0; i<n; i++){
                ret[i] = tsum/nums[i];
            }
        }
        return ret;
    }
};
