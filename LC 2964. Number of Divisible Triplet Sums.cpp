class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                m[(nums[i]+nums[j])%d]++;
            }
        }
        for(auto it:m){
            cout << it.first << " " << it.second << endl;
        }
        int ret = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                m[(nums[i] + nums[j])%d]--;
            }
            ret += m[(d-nums[i]%d)%d];
        }
        return ret;
    }
};
