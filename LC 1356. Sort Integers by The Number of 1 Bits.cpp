bool compareInterval(int i1, int i2) {
    int tmp1 = 0, tmp2 = 0, tmp3 = i1, tmp4 = i2;
    while(i1){
        tmp1 += i1&1;
        i1 >>= 1;
    }
    while(i2){
        tmp2 += i2&1;
        i2 >>= 1;
    }
    return (tmp1 < tmp2) || (tmp1 == tmp2 && tmp3 < tmp4); 
}

class Solution {

public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(),compareInterval);
        
        return arr;
    }
};
