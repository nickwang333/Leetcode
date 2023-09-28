class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        stack<int> s, spos;
        for(int i=0; i<n; i++){
            if(s.empty()){
                s.push(nums[i]);
                spos.push(i);
            }
            else{
                while(!s.empty() && s.top() > nums[i]){
                    int tmp = s.top();
                    s.pop();
                    int tmp2 = spos.top();
                    spos.pop();
                    ret += (i-tmp2);
                }
                s.push(nums[i]);
                spos.push(i);
            }
        }
        while(!s.empty()){
            int tmp = s.top();
            s.pop();
            int tmp2 = spos.top();
            spos.pop();
            ret += (n-tmp2);
        }
        return ret;
    }
};
