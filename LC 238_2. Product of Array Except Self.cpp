class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), tmp = 1;
        vector<int> v(n, 1);
        for(int i=n-1; i>0; i--){
            tmp *= nums[i];
            v[i-1] = tmp;
        }
        tmp = 1;
        for(int i=1; i<n; i++){
            tmp *= nums[i-1];
            v[i] *= tmp;
        }
        return v;
    }
};
