class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long> v(5,1);//[a,e,i,o,u]
        long mod = 1000000007;
        for(int i=1; i<n; i++){
            vector<long> next(5,0);
            next[0] = (v[1]+v[2]+v[4])%mod;
            next[1] = (v[0]+v[2])%mod;
            next[2] = (v[1]+v[3])%mod;
            next[3] = v[2]%mod;
            next[4] = (v[2]+v[3])%mod;
            v = next;
        }
        long ret = 0;
        for(int i:v){
            ret += i;
        }
        return ret%mod;
    }
};
