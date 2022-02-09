class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ret = 0;
        map<int, int> m;
        for(int i:nums){
            m[i]++;
        }
        for(auto it = m.begin(); it!=m.end(); it++){
            if(k==0){
                if(it->second > 1){
                    ret++;
                }
            }
            else{
                auto it2 = m.find(it->first+k);
                if(it2 != m.end()){
                    ret++;
                }
            }
        }
        return ret;
    }
};
