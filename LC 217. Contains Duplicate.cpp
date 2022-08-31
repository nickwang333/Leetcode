class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
            if(m[i]>=2){
                return true;
            }
        }
        return false;
    }
};
