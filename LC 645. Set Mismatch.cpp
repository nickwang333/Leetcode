class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret;
        unordered_map<int, int> m;
        for(int i:nums){
            m[i]++;
        }
        for(int i=1; i<=nums.size(); i++){
            if(m[i] == 2){
                ret.push_back(i);
            }
        }
        for(int i=1; i<=nums.size(); i++){
            if(m[i] == 0){
                ret.push_back(i);
            }
        }
        return ret;
    }
};
