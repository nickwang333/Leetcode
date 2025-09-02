class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        for(int i=0; i<n; i++){
            m[nums[i]]--;
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            } 
            for(int j=i+1; j<n; j++){
                m[nums[j]]--;
                if(j != i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int val = -(nums[i] + nums[j]);
                if(val < 0){
                    break;
                }
                if(m[val] != 0){
                    vector<int> tmp{nums[i], nums[j], val};
                    ret.push_back(tmp);
                }
            }
            for(int j=i+1; j<n; j++){
                m[nums[j]]++;
            }
        }
        return ret;
    }
};
