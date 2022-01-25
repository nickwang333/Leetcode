class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long n = differences.size(), ma = 0, mi = 0, ret = 0;
        for(int i=0; i<n; i++){
            ma += differences[i];
            mi += differences[i];
            ma = max(long(ma), max(long(0), long(differences[i])));
            mi = min(long(mi), min(long(0), long(differences[i])));
            ret = max(long(ma), max(long(ret),long(-mi)));
        }
        int tmp = upper-lower-ret+1;
        return max(0, tmp);
    }
};
