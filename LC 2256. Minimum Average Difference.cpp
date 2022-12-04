class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long ret = -1, tsum = 0, tloss = 0, tmp = INT_MAX, n = nums.size();
        for(int i:nums){
            tsum += i;
        }
        for(int i=0; i<nums.size(); i++){
            tsum -= nums[i];
            tloss += nums[i];
            int tmpv;
            if(i == n-1){
                tmpv = abs(tloss/(i+1) - 0);
            }
            else{
                tmpv = abs(tloss/(i+1) - tsum/(n-i-1));
            }
            if(tmp > tmpv){
                tmp = tmpv;
                ret = i;
            }
        }
        return ret;
    }
};
