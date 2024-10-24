class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size(), index = 0, count = 0;
        for(int i=1; i<n; i++){
            if(nums[i] <= nums[i-1]){
                index = i-1;
                count++;
            }
        }
        if(count > 1){
            return false;
        }
        // Check for index i-1, if this is strictly increasing: i-2, i+1
        vector<int> v1, v2;
        for(int i=0; i<n; i++){
            if(i != index){
                v1.push_back(nums[i]);
            }
            if(i != index+1){
                v2.push_back(nums[i]);
            }
        }
        int flag1 = 0, flag2 = 0;
        for(int i=1; i<n-1; i++){
            if(v1[i] <= v1[i-1]){
                flag1 = 1;
            }
            if(v2[i] <= v2[i-1]){
                flag2 = 1;
            }
        }
        return flag1 == 0 || flag2 == 0;
    }
};
