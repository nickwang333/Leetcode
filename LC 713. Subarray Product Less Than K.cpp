class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        vector<int> v = nums;
        int fp = 0, ret = 0;
        for(int i =0; i<nums.size(); i++){
            if(i!=0){
                v[i]*=v[i-1];
            }
            if(v[i] < k){
                ret += (i-fp+1);
            }
            else{
                while(fp <= i && v[i]>=k){
                    v[i] /= nums[fp];
                    fp++;
                }
                ret += (i-fp+1);
            }
        }
        return ret;
    }
};
