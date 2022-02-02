class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> m;
        for(int i:nums){
            m[i]++;
        }
        while(1){
            if(m[original] != 0){
                original *= 2;
            }
            else{
                break;
            }
        }
        return original;
    }
};
