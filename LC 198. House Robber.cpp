class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> v(n,0);
        v[0] = nums[0];
        v[1] = nums[1];
        for(int i=2; i<n; i++){
            if(i==2){
                v[i] = v[0]+nums[i];
            }
            else{
                v[i] = nums[i]+max(v[i-2], v[i-3]);
            }
        }
        return max(v[n-1], v[n-2]);
    }
};
