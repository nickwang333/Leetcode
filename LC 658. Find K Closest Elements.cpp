class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ret;
        map<int, vector<int>> m;
        for(int i:arr){
            m[abs(i-x)].push_back(i);
        }
        
        for(auto it:m){
            if(k == 0){
                break;
            }
            for(int i:it.second){
                k--;
                ret.push_back(i);
                if(k == 0){
                    break;
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
