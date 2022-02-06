class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), ret = 0, curr = 0;
        if(n==1){
            return 1;
        }
        for(int i=2; i<n; i++){
            if(nums[i] == nums[curr]){
                continue;
            }
            else{
                nums[curr+2] = nums[i];
                curr++;
            }
        }
        return curr+2;
    }
};
