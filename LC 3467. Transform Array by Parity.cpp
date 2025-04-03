class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size(), end = n-1;
        vector<int> ret(n, 0);
        for(int i:nums){
            if(i % 2 == 1){
                ret[end] = 1;
                end--;
            }
        }
        return ret;
    }
};
