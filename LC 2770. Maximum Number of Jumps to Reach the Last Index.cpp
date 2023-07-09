class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v(n, -1);
        v[0] = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(v[i] != -1 && abs(nums[i]-nums[j]) <= target){
                    if(v[j] == -1){
                        v[j] = v[i] + 1;
                    }
                    else{
                        v[j] = max(v[j], v[i]+1);
                    }
                }
            }
        }
        return v[n-1];
    }
};
