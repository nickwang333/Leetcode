class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), ret = 0, flag = 1;
        vector<int> v(n+1,0);
        for(int i=0; i<n; i++){
            if(seats[i]==0){
                v[i+1] = v[i]+1;
                if(flag == 1){
                    ret = max(ret, v[i+1]);
                }
                ret = max(ret, (v[i+1]+1)/2);
            }
            else{
                flag = 0;
            }
        }
        ret = max(ret, v[n]);
        return ret;
    }
};
