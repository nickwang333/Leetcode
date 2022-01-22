class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size(), tmp = 0, total = 0, ret = 0;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            v[i] = gas[i] - cost[i];
            total += v[i];
            if(tmp+v[i]>=0){
                tmp = tmp+v[i];
                if(ret==-1){
                    ret = i;
                }
            }
            else{
                ret = -1;
                tmp = 0;
            }
        }
        if(total < 0){
            return -1;
        }
        else{
            return ret;
        }
    }
};
