class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> v(n, 0);
        vector<bool> ret(m, false);
        int count = 0;
        for(int i=0; i<n-1; i++){
            if((nums[i]+nums[i+1]) % 2 == 1){
                count++;
                v[i+1] = count;
            }
            else{
                v[i+1] = count;
            }
        }
        for(int i=0; i<m; i++){
            int tmp = v[queries[i][1]] - v[queries[i][0]];
            if(tmp == (queries[i][1] - queries[i][0])){
                ret[i] = true;
            }
        }
        return ret;
    }
};
