class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret;
        vector<int> noni(n,0), nond(n,0);
        vector<int> inc(n,true), dec(n,true);
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                if(i != n-1){
                    noni[i+1] = k-1;
                }
            }
            else if(nums[i] < nums[i-1]){
                if(i >= k){
                    nond[i-k] = k-1;
                }
            }
        }
        int tmp1 = 0, tmp2 = 0;
        for(int i=0; i<n; i++){
            tmp1 = max(tmp1,noni[i]);
            tmp2 = max(tmp2,nond[i]);
            if(tmp1 > 0){
                inc[i] = false;
                tmp1--;
            }
            if(tmp2 > 0){
                dec[i] = false;
                tmp2--;
            }
        }
        for(int i=k; i<n-k; i++){
            if(inc[i] && dec[i]){
                ret.push_back(i);
            }
        }
        return ret;
    }
};
