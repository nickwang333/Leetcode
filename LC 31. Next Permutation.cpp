class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        for(l=n-1; l>0; l--){
            if(nums[l] > nums[l-1]){
                break;
            }
        }
        if(l == 0){
            reverse(nums.begin(), nums.end());
        }
        else{
            l--;
            for(r=n-1; r>l; r--){
                if(nums[r] > nums[l]){
                    swap(nums[r], nums[l]);
                    reverse(nums.begin()+l+1, nums.end());
                    break;
                }
            }
        }
    }
};
