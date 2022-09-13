class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ret = 0, p = 0, g = 0, m = 0;
        vector<int> v = travel;
        unordered_map<char, int> m2;
        for(int i=1; i<v.size(); i++){
            v[i] += v[i-1];
        }
        for(int i=0; i<garbage.size(); i++){
            ret += garbage[i].size();
            for(char j:garbage[i]){
                if(j == 'P'){
                    p = i;
                }
                if(j == 'M'){
                    m = i;
                }
                if(j == 'G'){
                    g = i;
                }
            }
        }
        if(p != 0){
            ret += v[p-1];
        }
        if(g != 0){
            ret += v[g-1];
        }
        if(m != 0){
            ret += v[m-1];
        }
        return ret;
    }
};
