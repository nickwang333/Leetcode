class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ret = -1, n = nums.size(), tmp = 0;
        vector<int> v(n-1, 0);
        for(int i=1; i<nums.size(); i++){
            v[i-1] = nums[i] - nums[i-1];
        }
        for(int i=0; i<n-1; i++){
            if(v[i] == 1 && tmp%2 == 0){
                tmp++;
            }
            else if(v[i] == -1 && tmp%2 == 1){
                tmp++;
            }
            else{
                if(tmp != 0){
                    ret = max(ret,tmp+1);
                    tmp = 0;
                }
                if(v[i] == 1){
                    tmp++;
                    ret = max(ret,tmp+1);
                }
            }
        }
        if(tmp != 0){
            ret = max(ret, tmp+1);
        }
        return ret;
    }
};
