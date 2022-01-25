class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), posi = 0, nega = 1;
        vector<int> ret(n);
        for(int i:nums){
            if(i>0){
                ret[posi] = i;
                posi+=2;
            }
            else{
                ret[nega] = i;
                nega+=2;
            }
        }
        return ret;
    }
};
