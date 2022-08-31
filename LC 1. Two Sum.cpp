class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> m2;
        unordered_map<int, int> m;
        vector<int> ret;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            m2[nums[i]].push_back(i);
        }
        for(int i=0; i<nums.size(); i++){
            int tmp = target-nums[i];
            if(m[tmp] != 0){
                if(tmp*2 == target){
                    if(m[tmp] == 2){
                        vector<int> ret{m2[nums[i]][0], m2[tmp][1]};
                        return ret;
                    }
                }
                else{
                    vector<int> ret{m2[nums[i]][0], m2[tmp][0]};
                    return ret;
                }
            }
        }
        return ret;
    }
};
