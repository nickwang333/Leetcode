class Solution {
public:
    int countOrders(int n) {
        long ret = 1;
        for(int i=1; i<n; i++){
            ret = ret * (2*i+1) % 1000000007 * (2*i+2) / 2 % 1000000007;
        }
        return ret;
    }
};
