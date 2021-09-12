class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int fp,sp;
        vector<int> v;
        vector<vector<int>> ret;
        if(nums.size()<3){
            return ret;
        }
        for(int i=0; i<nums.size()-2; i++){
            fp = i+1, sp = nums.size()-1;
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            while(fp<sp){
                int tsum = nums[i] + nums[fp] + nums[sp];
                if(tsum == 0){
                    v.push_back(nums[i]);
                    v.push_back(nums[fp]);
                    v.push_back(nums[sp]);
                    if (!(fp > i + 1 && nums[fp] == nums[fp- 1])){
                        ret.push_back(v);
                    }
                    fp++;
                    sp--;
                }
                else if(tsum>0){
                    sp--;
                }
                else{
                    fp++;
                }
                v.clear();
            }
        }
        return ret;
    }
};
