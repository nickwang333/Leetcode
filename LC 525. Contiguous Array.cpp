class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = 0, tmp = 0;
        unordered_map<int, vector<int>> m;
        m[0].push_back(0);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                tmp--;
            }
            else{
                tmp++;
            }
            m[tmp].push_back(i+1);
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            n = max(n, it->second[it->second.size()-1] - it->second[0]);
        }
        return n;
    }
};
