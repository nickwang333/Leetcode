class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> ret(n);
        if(k/2 >= n){
            return (1+n)*n/2;
        }
        if(k%2 == 0){
            cout << k << " " << (k -1+(n-k/2)-1) << " " << (n-k/2);
            return (1+k/2)*k/4+(k+k-1+(n-k/2))*(n-k/2)/2;
        }
        else{
            return (1+k/2)*(k/2)/2+(k+k+(n-k/2)-1)*(n-k/2)/2;
        }
    }
};
