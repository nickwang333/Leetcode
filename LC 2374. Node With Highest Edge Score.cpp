class Solution {
public:
    int edgeScore(vector<int>& edges) {
        long n = edges.size(), ret = 0, maxi = 0;
        vector<long> v(n,0);
        for(int i=0; i<n; i++){
            v[edges[i]]+=i;
        }
        for(int i=0; i<n; i++){
            if(v[i] > maxi){
                maxi = v[i];
                ret = i;
            }
        }
        return ret;
    }
};
