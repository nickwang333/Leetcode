class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), prev = 0, ret = 1;
        unordered_map<int, int> count;
        priority_queue<int> q1, q2;
        // q1 max, q2 min
        for(int i=0; i<n; i++){
            count[nums[i]]++;
            q1.push(nums[i]);
            q2.push(-nums[i]);
            int tmp1 = q1.top();
            int tmp2 = -q2.top();
            while(prev <= i && tmp1 - tmp2 > limit){
                count[nums[prev]]--;
                while(!q1.empty() && count[tmp1] == 0){
                    q1.pop();
                    tmp1 = q1.top();
                }
                while(!q2.empty() && count[tmp2] == 0){
                    q2.pop();
                    tmp2 = -q2.top();
                }
                prev++;
            }
            ret = max(ret, i-prev+1);
        }
        return ret;
    }
};
