class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size(), tmp = 0;
        vector<int> v(n+1, 0);
        for(int i=0; i<=n-k; i++){
            tmp += v[i];
            if(nums[i] > tmp){
                v[i] += nums[i]-tmp;
                v[i+k] -= nums[i]-tmp;
                tmp = nums[i];
            }
        }
        tmp = 0;
        for(int i=0; i<n; i++){
            tmp += v[i];
            if(tmp != nums[i]){
                return false;
            }
        }
        return true;
    }
};

