class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        long prev = -1;
        vector<string> ret;
        map<long, long> m;
        if(nums.size() == 0){
            return ret;
        }
        if(nums.size() == 1){
            ret.push_back(to_string(nums[0]));
            return ret;
        }
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]+1){
                if(prev == -1){
                    prev = i-1;
                    m[nums[i-1]] = 2;
                }
                else{
                    m[nums[prev]]++;
                }
            }
            else{
                if(prev != -1){
                    prev = -1;
                }
                else{
                    m[nums[i-1]] = 1;
                }
                if(i == nums.size()-1){
                    m[nums[i]] = 1;
                }
                prev = -1;
            }
        }
        for(auto i:m){
            if(i.second == 1){
                ret.push_back(to_string(i.first));
            }
            else{
                string tmp2 = to_string(i.first);
                tmp2 += "->";
                tmp2 += to_string(i.first + i.second - 1);
                ret.push_back(tmp2);
            }
            
        }
        return ret;
    }
};
