class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        for(int i=0; i<n; i++){
            unordered_map<int, int> m;
            for(int j=i; j>=0; j--){
                m[nums[j]]++;
                ret += pow(m.size(), 2);
            }
        }
        return ret;
    }
};
