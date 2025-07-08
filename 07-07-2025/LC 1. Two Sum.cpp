class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            m[nums[i]].push_back(i);
        }
        for(int i:nums){
            if(i*2 == target){
                if(m[i].size() >= 2){
                    vector<int> v{m[i][0], m[i][1]};
                    return v;
                }
            }
            else{
                if(m[target-i].size() >= 1){
                    vector<int> v{m[i][0], m[target-i][0]};
                    return v;
                }
            }
        }
        return vector<int>{0,1};
    }
};
