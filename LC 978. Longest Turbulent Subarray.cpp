class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int ret = 1;
        vector<int> v(n,1);
        if(n>1 && arr[0] != arr[1]){
            v[1] = 2;
            ret = 2;
        }
        for(int i=2; i<n; i++){
            long a = arr[i]-arr[i-1];
            long b = arr[i-1]-arr[i-2];
            if((a*b)<0){
                v[i] = v[i-1]+1;
            }
            else{
                if(arr[i] != arr[i-1]){
                    v[i] = 2;
                }
            }
            ret = max(ret, v[i]);
        }
        return ret;
    }
};
