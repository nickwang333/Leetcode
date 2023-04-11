class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<long long>> m;
        vector<long long> ret(nums.size());
        for(int i=0; i<nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        for(auto it = m.begin(); it != m.end(); it++){
            long long total = 0, sz = it->second.size(), tmp2 = 0;
            for(int j=0; j<it->second.size(); j++){
                total += it->second[j];
            }
            for(int j=0; j<it->second.size(); j++){
                if(j == 0){
                    ret[it->second[j]] = total - sz*it->second[j];
                    tmp2 += sz*it->second[j];
                    total -= it->second[j];
                    sz--;
                }
                else{
                    ret[it->second[j]] = j*it->second[j] - it->second[j-1];
                    ret[it->second[j]] += abs(total-sz*it->second[j]);
                    total -= it->second[j];
                    it->second[j] += it->second[j-1];
                    sz--;
                }
            }
        }
        return ret;
    }
};
