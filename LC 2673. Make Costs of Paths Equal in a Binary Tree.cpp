class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        queue<int> q;
        q.push(0);
        vector<int> tsum = cost;
        int maxi = 0, ret = 0;
        for(int i=1; i<n; i++){
            tsum[i] += tsum[(i+1)/2-1];
            maxi = max(maxi, tsum[i]);
        }
        for(int i=n/2-1; i>=0; i--){
            tsum[i] = max(tsum[i*2+2], tsum[i*2+1]);
        }
        for(int i:tsum){
            cout << i << " ";
        }
        cout << endl;
        vector<int> offset(n,0);
        for(int i=1; i<n; i++){
            tsum[i] += (offset[(i+1)/2-1]);
            ret += (maxi - tsum[i]);
            offset[i] += (maxi - tsum[i]);
            if((i*2+2) < n){
                offset[i*2+1] = offset[i];
                offset[i*2+2] = offset[i];
            }
        }
        return ret;
    }
};
