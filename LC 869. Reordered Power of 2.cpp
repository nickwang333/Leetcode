class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<string, int> m;
        int ret = 1;
        m["1"] = 1;
        for(int i=0; i<30; i++){
            ret *= 2;
            string tmp = to_string(ret);
            sort(tmp.begin(), tmp.end());
            m[tmp] = 1;
        }
        string tmp2 = to_string(n);
        sort(tmp2.begin(), tmp2.end());
        return m[tmp2] == 1;
    }
};
