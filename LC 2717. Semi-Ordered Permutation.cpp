class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int ret = 0, index1 = -1, index2 = -1, n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                index1 = i;
            }
            else if(nums[i] == n){
                index2 = i;
            }
        }
        ret = index1 + (n-index2-1);
        if(index1 > index2){
            ret--;
        }
        return ret;
    }
};
