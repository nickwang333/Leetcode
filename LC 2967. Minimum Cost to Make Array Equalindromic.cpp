class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        long long tmp1 = 0, tmp2 = 0;
        int n = nums.size(), cand1, cand2, mid;
        sort(nums.begin(), nums.end());
        mid = nums[n/2];
        for(int i=mid; i>=0; i--){
            string tmp = to_string(i);
            reverse(tmp.begin(), tmp.end());
            if(tmp == to_string(i)){
                cand1 = i;
                break;
            }
        }
        for(int i=mid; i<=INT_MAX; i++){
            string tmp = to_string(i);
            reverse(tmp.begin(), tmp.end());
            if(tmp == to_string(i)){
                cand2 = i;
                break;
            }
        }
        for(auto i:nums){
            tmp1 += abs(i-cand1);
            tmp2 += abs(i-cand2);
        }
        return min(tmp1, tmp2);
    }
};
