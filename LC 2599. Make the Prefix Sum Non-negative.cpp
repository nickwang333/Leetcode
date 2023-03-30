class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        long long ret = 0, tsum = 0;
        priority_queue<long long> q;
        for(int i=0; i<nums.size(); i++){
            q.push(-nums[i]);
            tsum += nums[i];
            if(tsum < 0){
                ret++;
                tsum += q.top();
                q.pop();
            }
        }
        return ret;
    }
};
