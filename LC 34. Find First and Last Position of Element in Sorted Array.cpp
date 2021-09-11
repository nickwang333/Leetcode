class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2,-1);
        int n = nums.size();
        if(n==0){
            return ret;
        }
        if(n==1){
            if(nums[0]!=target){
                return ret;
            }
        }
        int low = 0, high = n-1;
        while(low < high){
            int mid = (low+high)/2;
            if(nums[mid]<target){
                low = mid +1;
            }
            else{
                high = mid;
            }
        }
        if(nums[low] == target){
            ret[0] = low;
            ret[1] = low;
        }
        else{
            ret[0] = -1;
        }
        high = n-1;
        while(low < high){
            int mid = (low+high)/2;
            if(nums[mid]>target){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(nums[high] == target){
            ret[1] = high;
        }
        else if(high>0 && nums[high-1] == target){
            ret[1] = high-1;
        }
        return ret;
    }
};
