class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ret = 0, sz = nums.size();
        unordered_map<int, int> m;
        for(int i:nums){
            m[i]++;
        }
        int n = m.size();
        for(int i=0; i<sz; i++){
            unordered_map<int, int> m2;
            for(int j=i; j<sz; j++){
                m2[nums[j]]++;
                if(m2.size() == n){
                    ret += (sz-j);
                    break;
                }
            }
        }
        return ret;
    }
};
