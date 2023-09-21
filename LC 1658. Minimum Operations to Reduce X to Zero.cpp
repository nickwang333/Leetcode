class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tsum = 0, n = nums.size(), pointer = -1, ret = -1;
        for(int i=n-1; i>=0; i--){
            tsum += nums[i];
            if(tsum >= x){
                pointer = i;
                break;
            }
        }
        if(tsum < x){
            return -1;
        }
        if(tsum == x){
            ret = n-pointer;
        }
        for(int i=0; i<n; i++){
            tsum += nums[i];
            while(pointer <= n-1 && tsum > x){
                tsum -= nums[pointer];
                pointer++;
            }
            
            if(tsum == x){
                if(ret == -1){
                    ret = n-pointer+i+1;
                }
                else{
                    ret = min(ret, n-pointer+i+1);
                }
            }
        }
        return ret;
    }
};
