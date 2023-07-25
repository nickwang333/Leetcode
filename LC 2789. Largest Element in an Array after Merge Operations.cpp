class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long ret = 0, tmp = 0;
        int n = nums.size();
        queue<long long> q;
        q.push(nums[n-1]);
        ret = max(ret, q.front());
        for(int i=n-2; i>=0; i--){
            ret = max(ret, q.front());
            if(q.front() >= nums[i]){
                q.push(nums[i] + q.front());
                q.pop();
            }
            else{
                q.pop();
                q.push(nums[i]);
            }
            ret = max(ret, q.front());
        }
        return ret;
    }
};
