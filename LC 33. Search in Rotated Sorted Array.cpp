class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int high = n-1, low = 0;
        while(high > low){
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[high]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        int low1 = low;
        high = n-1;
        while(low1 < high){
            int mid = low1 + (high-low1)/2;
            if(nums[mid] < target){
                low1 = mid+1;
            }
            else{
                high = mid;
            }
        }
        if(nums[low1] == target){
            return low1;
        }
        low1 = 0, high = low-1;
        while(low1 < high){
            int mid = low1 + (high-low1)/2;
            if(nums[mid] < target){
                low1 = mid+1;
            }
            else{
                high = mid;
            }
        }
        if(nums[low1] == target){
            return low1;
        }
        return -1;
        
    }
};
