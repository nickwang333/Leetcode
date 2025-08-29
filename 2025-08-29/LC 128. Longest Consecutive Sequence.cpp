class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i:nums) {
            m[i]++;
        }
        vector<int> v2;
        for(auto it:m){
            v2.push_back(it.first);
        }
        int n = nums.size(), ret = 0;
        for(int i:v2){
            if(m[i-1] == 0){
                int tmp = 1, curr = i;
                while(m[curr+1] != 0){
                    tmp++;
                    curr++;
                }
                ret = max(ret, tmp);
            }
        }
        return ret;
    }
};
