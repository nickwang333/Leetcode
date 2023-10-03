class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        int ret = 0;
        for(int i:nums){
            m[i]++;
        }
        for(auto i:m){
            if(i.second == 1){
                return -1;
            }
            ret += i.second/3;
            if(i.second % 3 != 0){
                ret++;
            }
        }
        return ret;
    }
};
