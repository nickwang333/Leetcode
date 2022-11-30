class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> v(1001, -1);
        unordered_map<int, int> m, m2;
        for(int i:arr){
            m[i]++;
        }
        for(auto i:m){
            if(v[i.second] != -1){
                return false;
            }
            v[i.second] = 1;
        }
        return true;
    }
};
