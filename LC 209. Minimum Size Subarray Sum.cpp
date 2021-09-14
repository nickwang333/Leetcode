class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> v = nums;
        int low = 0, ret = 0;
        for(int i=0; i<nums.size(); i++){
            if(i!=0){
                v[i] += v[i-1];
            }
            if(v[i] >= s){
                if(ret==0){
                    ret = i-low+1;
                }
                else{
                    ret = min(ret, i-low+1);
                }
                while(low<=i && v[i]>=s){
                    v[i] -= nums[low];
                    low++;
                }
                ret = min(ret, i-low+2);
            }
        }
        return ret;
    }
};
