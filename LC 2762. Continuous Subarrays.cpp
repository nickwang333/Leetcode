class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ret = 0, n = nums.size(), fp = 0;
        map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
            auto it1 = m.end(), it2 = m.begin();
            it1--;
            while(fp < i && (it1->first - it2->first) > 2){
                m[nums[fp]]--;
                if(m[nums[fp]] == 0){
                    m.erase(nums[fp]);
                }
                it1 = m.end();
                it1--;
                it2 = m.begin();
                fp++;
            }
            ret += (i-fp+1);
        }
        return ret;
    }
};
