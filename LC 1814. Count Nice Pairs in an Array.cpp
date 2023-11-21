class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        long ret = 0, mod = 1000000007;
        for(int i:nums){
            string tmp = to_string(i);
            reverse(tmp.begin(), tmp.end());
            int tmp2 = stoi(tmp);
            m[i-tmp2].push_back(i);
        }
        for(auto i:m){
            long sz = i.second.size()-1;
            long tmp2 = sz*(1+sz)/2%mod;
            ret += tmp2;
            ret %= mod;
        }
        
        return ret;
    }
};
