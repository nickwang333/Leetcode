class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        if(n < 3){
            return false;
        }
        for(int i=0; i<n-1; i++){
            if(m[nums[i]+nums[i+1]] == 1){
                return true;
            }
            m[nums[i]+nums[i+1]] = 1;
        }
        return false;
    }
};
