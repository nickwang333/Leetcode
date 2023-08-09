class Solution {
public:
    bool available(int mid, vector<int>& nums, int p){
        int n = nums.size(), counter = 0;
        for(int i=0; i<n-1; i++){
            if((nums[i+1]-nums[i]) <= mid){
                counter++;
                i++;
            }
            if(counter >= p){
                return true;
            }
        }
        return false;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        while(low < high){
            int mid = (high+low) / 2;
            if(available(mid, nums, p)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
