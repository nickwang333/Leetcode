class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> ret;
        int n = numWays.size();
        vector<int> v(n, 0);
        // 0 1 0 2 0 3 0 4 0
        for(int i=0; i<n; i++){
            if(numWays[i]-v[i] == 1){
                ret.push_back(i+1);
                v[i]++;
                for(int j=0; j<n; j++){
                    if(j+i+1 >= n){
                        break;
                    }
                    v[j+i+1] += v[j];
                }
            }
        }
        for(int i=0; i<n; i++){
            if(v[i] != numWays[i]){
                return vector<int>{};
            }
        }
        return ret;
    }
};
