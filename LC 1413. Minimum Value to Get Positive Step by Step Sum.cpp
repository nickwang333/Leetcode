class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size(), mini = nums[0];
        vector<int> v(n,0);
        v[0] = nums[0];
        for(int i=1; i<n; i++){
            v[i] = v[i-1]+nums[i];
            mini = min(mini, v[i]);
        }
        if(mini>0){
            return 1;
        }
        return -mini+1;
    }
};
