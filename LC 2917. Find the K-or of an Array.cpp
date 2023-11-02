class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> v(32, 0);
        int ret = 0;
        for(int i:nums){
            int counter = 0;
            while(i != 0){
                v[counter] += i%2;
                i/=2;
                counter++;
            }
        }
        for(int i=0; i<32; i++){
            if(v[i] >= k){
                ret += pow(2, i);
            }
        }
        return ret;
    }
};
