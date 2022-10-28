class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        int counter = 0;
        unordered_map<int,int> m1;
        map<int,vector<int>> m2;
        for(int i:nums){
            m1[i]++;
        }
        for(auto i:m1){
            m2[i.second].push_back(i.first);
        }
        for(auto it = m2.rbegin(); it != m2.rend(); it++){
            for(int i:it->second){
                ret.push_back(i);
                counter++;
            }
            if(counter == k){
                break;
            }
        }
        return ret;
    }
};
