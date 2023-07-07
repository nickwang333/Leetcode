class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ret;
        vector<int> primes(n+1, 1);
        primes[0] = 0;
        primes[1] = 0;
        for(int i=2; i<n+1; i++){
            if(primes[i] == 1){
                for(int j=i*2; j<n+1; j+=i){
                    primes[j] = 0;
                }
            }
        }
        for(int i=2; i<=n/2; i++){
            if(primes[i] == 1 && primes[n-i] == 1){
                vector<int> tmp{i, n-i};
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};
