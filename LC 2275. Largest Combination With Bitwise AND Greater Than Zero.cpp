class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        unordered_map<int, vector<int>> m;
        for(int i=0; i<n; i++){
            int tmp = candidates[i];
            int counter = 0;
            while(tmp > 0){
                if(tmp % 2 == 1){
                    m[counter].push_back(i);
                }
                tmp /= 2;
                counter++;
            }
        }
        int ret = 1;
        for(auto i:m){
            int sz = i.second.size();
            ret = max(ret, sz);
        }
        return ret;
    }
};
