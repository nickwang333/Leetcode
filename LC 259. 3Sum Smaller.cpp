class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size(), ret = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                int tsum = nums[i] + nums[j];
                int low = j+1, high = n-1, mid;
                while(low <= high){
                    mid = (high-low)/2 + low;
                    int val = target-tsum;
                    if(nums[mid] < val){
                        low = mid+1;
                    }
                    else{
                        high = mid-1;
                    }
                }
                ret += (low-j-1);
            }
        }
        return ret;
    }
};
