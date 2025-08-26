class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), p0 = 0, p1 = 1;
        while(p1 < n){
            while(p1 < n && nums[p1] == nums[p0]){
                p1++;
            }
            if(p0 < n+1 && p1 != n){
                nums[p0+1] = nums[p1];
                p0++;
            }
        }
        return p0+1;
    }
};
