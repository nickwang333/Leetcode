class Solution {
public:
    vector<bool> generate_prime(int n){
        vector<bool> v(n+1, true);
        v[0] = false;
        v[1] = false;
        for(int i=2; i<n; i++){
            if(v[i]){
                for(int j=2; j<n; j++){
                    if(j*i > n){
                        break;
                    }
                    v[j*i] = false;
                }
            }
        }
        return v;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i:nums){
            m[i]++;
        }
        vector<bool> isPrime = generate_prime(100);
        for(auto i:m){
            if(isPrime[i.second]){
                return true;
            }
        }
        return false;
    }
};
