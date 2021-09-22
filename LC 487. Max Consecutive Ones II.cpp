class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> v(1); v[0] = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                v.push_back(i+1);
            }
        }
        v.push_back(nums.size()+1);
        if(v.size()<4){
            return nums.size();
        }
        int ret = v[2]-v[0]-1;
        for(int i=2; i<v.size(); i++){
            ret = max(ret, v[i]-v[i-2]-1);
        }
        for(int i:v){
            cout << i;
        }
        return ret;
    }
};
