class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int total = nums[0];
        m[nums[0]%k]++;
        if(nums.size() < 2){
            return false;
        }
        for(int i = 1; i<nums.size(); i++){
            total += nums[i];
            m[total%k]++;
            m[(total-nums[i])%k]--;
            if(total%k == 0 || m[total%k] > 1){
                cout <<  total-nums[i-1];
                return true;
            }
            m[(total-nums[i])%k]++;
        }
        return false;
    }
};
