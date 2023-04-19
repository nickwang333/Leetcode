class Solution {
public:
    double maxPrice(vector<vector<int>>& items, int capacity) {
        double ret = 0;
        map<double, vector<int>> m;
        for(auto i:items){
            double tmp = double(i[0])/double(i[1]);
            m[tmp].push_back(i[1]);
        }
        for(auto it = m.rbegin(); it != m.rend(); it++){
            for(int j:it->second){
                if(capacity > j){
                    capacity -= j;
                    ret += j*it->first;
                }
                else{
                    ret += it->first*capacity;
                    capacity = 0;
                }
            }
        }
        if(capacity>0){
            return -1;
        }
        return ret;
    }
};
