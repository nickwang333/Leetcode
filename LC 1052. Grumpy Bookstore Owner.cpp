class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        //[1,0,1,2,1,1,7,5]
        //[0,1,0,1,0,1,0,1]
        int n = customers.size(), ret = 0, tmp = 0;
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            if(grumpy[i] == 0){
                tmp += customers[i];
            }
        }
        for(int i=0; i<n; i++){
            if(i < minutes){
                if(grumpy[i] == 1){
                    tmp += customers[i];
                }
            }
            else{
                if(grumpy[i] == 1){
                    tmp += customers[i];
                }
                if(grumpy[i-minutes] == 1){
                    tmp -= customers[i-minutes];
                }
            }
            ret = max(ret, tmp);
        }
        return ret;
    }
};
