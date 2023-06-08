class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i:nums){
            m[i]++;
        }
        return m[target] > nums.size()/2;
    }
};
