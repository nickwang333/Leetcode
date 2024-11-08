class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int, int> m;
        vector<int> ret;
        for(int i:arr1){
            m[i]++;
        }
        for(int i:arr2){
            m[i]++;
        }
        for(int i:arr3){
            m[i]++;
        }
        for(auto it:m){
            if(it.second == 3){
                ret.push_back(it.first);
            }
        }
        return ret;
    }
};
