class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        map<int, int> m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i < k){
                m[-nums[i]]++;
                if(i == k-1){
                    ret.push_back(-m.begin()->first);
                }
            }
            else{
                m[-nums[i-k]]--;
                if( m[-nums[i-k]] == 0){
                    m.erase(-nums[i-k]);
                }
                m[-nums[i]]++;
                ret.push_back(-m.begin()->first);
            }
        }
        return ret;
    }
};
