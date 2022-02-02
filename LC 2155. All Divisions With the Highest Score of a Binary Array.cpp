class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> ret, v(2,0);
        for(int i:nums){
            v[i]++;
        }
        int maxi = v[1], tmp = v[1];
        ret.push_back(0);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                tmp++;
                if(tmp > maxi){
                    vector<int> v_tmp(0);
                    ret = v_tmp;
                    ret.push_back(i+1);
                    maxi = tmp;
                }
                else if(tmp == maxi){
                    ret.push_back(i+1);
                }
            }
            else{
                tmp--;
            }
        }
        return ret;
    }
};
