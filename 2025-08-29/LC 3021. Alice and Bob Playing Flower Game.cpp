class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ret = 0;
        long long nl = n, ml = m;
        ret += (nl%2 + nl/2) * (ml/2);
        ret += (nl/2) * (ml%2 + ml/2);
        return ret;
    }
};
