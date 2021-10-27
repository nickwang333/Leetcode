class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it1 = upper_bound(nums.begin(), nums.end(), target);
        auto it2 = lower_bound(nums.begin(), nums.end(), target);
        if(it2==nums.end() && it1==nums.end()){
            return nums.size();
        }
        if(*it2==target){
            return it2-nums.begin();
        }
        return it1-nums.begin();
    }
};
