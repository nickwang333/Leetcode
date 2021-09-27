class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> v(amount+1, -1);
        v[0] = 0;
        for(int i=0; i<amount; i++){
            if(v[i]!=-1){
                for(int j:coins){
                    long long tmp = long(i)+long(j);
                    if(tmp<=amount){
                        if(v[i+j]==-1){
                            v[i+j] = v[i]+1;
                        }
                        else{
                            v[i+j] = min(v[i+j], v[i]+1);
                        }
                    }
                }
            }
        }
        return v[amount];
    }
};
