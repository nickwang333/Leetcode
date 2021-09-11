class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int high = n-1, low = 0;
        while(high > low){
            int mid = low + (high-low)/2;
            if(nums[high] > nums[mid]){
                high = mid; 
            }
            else{
                low = mid + 1;
            }
        }
        return nums[low];
    }
};
