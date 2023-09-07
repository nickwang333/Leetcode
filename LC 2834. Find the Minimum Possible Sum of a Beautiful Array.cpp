class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        long begin = 1, ret = 0, mod = 1000000007, sz = target/2, target2 = target, n2 = n;
        long ret1 = (1+n2)*n2/2%mod;
        // target .. target + n - sz -1  
        long ret2 = ((1+sz)*sz/2 + (n-sz) * (2*target2+n-sz-1)/2)%mod;
        return (sz >= n) ? ret1 : ret2;
    }
};
