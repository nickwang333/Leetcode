class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        int ret = 0;
        vector<int> v(n+1,0);
        for(int i:queries){
            v[i]++;
        }
        for(int i=0; i<=n; i++){
            ret += (v[i]%2);
            if(i*2 <= n){
                v[i*2] += v[i];
            }
            if(i*2+1 <= n){
                v[i*2+1] += v[i];
            }
        }
        return ret;
    }
};
