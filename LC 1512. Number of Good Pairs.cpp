class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int ret = 0;
        for(int i:nums){
            m[i]++;
        }
        for(auto i:m){
            int tmp = (i.second-1) * i.second/2;
            ret += tmp;
        }
        return ret;
    }
};
