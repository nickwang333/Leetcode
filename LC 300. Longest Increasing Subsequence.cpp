class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ret = 1;
        vector<int> v(n,1);
        map<int, int> m;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    v[i] = max(v[i],v[j]+1);
                    ret = max(ret,v[i]);
                }
            }
        }
        return ret;
    }
};LC
