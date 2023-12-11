class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int ret = arr[0], tmp = 1, cur = arr[0], n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]){
                tmp++;
                if(tmp > n/4){
                    ret = cur;
                    return ret;
                }
            }
            else{
                tmp = 1;
                cur = arr[i];
            }
        }
        if(tmp > n/4){
            return cur;
        }
        return ret;
    }
};
