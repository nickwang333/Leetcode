class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i: nums){
            m[i] = 1;
        }
        m[0] = 1;
        return m.size()-1;
    }
};
