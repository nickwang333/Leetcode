class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int fp = 0, sp = 0, mini = nums[0], maxi = nums[0], n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                sp = i;
            }
            if(nums[i]<mini){
                mini = nums[i];
                fp = i;
            }
        }
        int ret = min(max(fp+1, sp+1), n-min(fp,sp));
        return min(ret, n-max(fp, sp)+1+min(sp, fp));
    }
};
