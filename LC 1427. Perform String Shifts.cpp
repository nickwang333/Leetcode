class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = 0, sz = s.size();
        for(auto i:shift){
            if(i[0] == 0){
                n += i[1];
            }
            else{
                n -= i[1];
            }
        }
        n %= sz;
        if(n < 0){
            n += sz;
        }
        return s.substr(n) + s.substr(0, n);
    }
};
