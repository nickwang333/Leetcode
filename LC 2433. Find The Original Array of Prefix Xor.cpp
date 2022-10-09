class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ret = pref;
        for(int i=1; i<n; i++){
            
            ret[i] = pref[i] ^ pref[i-1];
        }
        return ret;
    }
};
