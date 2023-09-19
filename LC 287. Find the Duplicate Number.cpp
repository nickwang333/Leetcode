class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), i=0, fp = nums[0], sp = nums[0];
        while(i == 0 || fp!=sp){
            i=1;
            fp = nums[nums[fp]];//jump twice
            
            sp = nums[sp];
        }
        sp = nums[0];
        while(fp != sp){
            sp = nums[sp];
            fp = nums[fp];
        }
        return sp;
    }
};
