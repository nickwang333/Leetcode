class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int tsum = 0;
        vector<int> v(1001, 0);
        for(auto i:trips){
            v[i[1]] += i[0];
            v[i[2]] -= i[0];
        }
        for(int i:v){
            tsum += i;
            if(tsum > capacity){
                return false;
            }
        }
        return true;
        
    }
};
