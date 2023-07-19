class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size(), domi = -1, tmp = 0, ret = -1;
        unordered_map<int, int> m;
        for(int i:nums){
            m[i]++;
            if(m[i]*2 > n){
                domi = i;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == domi){
                tmp++;
            }
            int lastlen = n-i-1;
            if(tmp*2 > i+1 && 2*(m[domi]-tmp) > lastlen){
                return i;
            }
        }
        return ret;
    }
};
