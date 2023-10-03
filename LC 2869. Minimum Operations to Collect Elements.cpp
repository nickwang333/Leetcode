class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size()-1, ret = 0, counter = 0;
        unordered_map<int, int> m;
        for(int i=n; i>=0; i--){
            m[nums[i]]++;
            if(m[nums[i]] == 1 && nums[i] <= k){
                counter++;
            }
            ret++;
            if(counter == k){
                return ret;
            }
        }
        return -1;
    }
};
