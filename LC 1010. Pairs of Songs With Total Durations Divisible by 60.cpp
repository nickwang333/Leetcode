class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ret = 0;
        vector<int> v(60,0);
        for(int i:time){
            v[i%60]++;
        }
        for(int i=0; i<=30; i++){
            if(i==0 || i==30){
                ret += (v[i]*(v[i]-1))/2;
            }
            else{
                ret += (v[i]*v[60-i]);
            }
        }
        return ret;
    }
};
