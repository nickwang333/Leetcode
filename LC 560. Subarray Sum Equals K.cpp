class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int counter=0, tsum=0, n=nums.size();
        map<int,int> m;
        m[0] = 1;
        for(int i=0; i<n; i++){
            tsum+=nums[i];
            counter += (m[tsum-k]);
            m[tsum]++;
        }
        return counter;
    }
};
