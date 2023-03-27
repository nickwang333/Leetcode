class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ret;
        sort(nums.begin(), nums.end());
        unordered_map<long long,long long> m;
        long long total = 0;
        m[0] = 0;
        for(int i=0; i<nums.size(); i++){
            total += nums[i];
            m[i+1] = total;
        }
        for(int i=0; i<queries.size(); i++){
            auto it = lower_bound(nums.begin(), nums.end(), queries[i]);
            long long tmp = 0;
            if(it != nums.end()){
                long long sz1 = it - nums.begin();
                long long sz2 = nums.size() - sz1;
                tmp += abs(((queries[i]) * sz1) - m[sz1]);
                tmp += abs(((queries[i]) * sz2) - total + m[sz1]);
            }
            else{
                long long tmp2 = queries[i]*nums.size();
                tmp = abs(tmp2 - total);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
