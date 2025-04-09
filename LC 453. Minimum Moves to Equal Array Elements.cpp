class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), maxi = nums[0], mini = nums[0];
        long total = 0;
        for(int i=0; i<n; i++){
            mini = min(mini, nums[i]);
        }
        for(int i=0; i<n; i++){
            total += (nums[i] - mini);
        }
        return total;
    }
};
