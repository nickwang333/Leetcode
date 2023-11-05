class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size(), maxi = arr[0], pos = 0;
        for(int i=1; i<n; i++){
            if(arr[i] > maxi){
                maxi = arr[i];
                pos = i-1;
                if(k == 1){
                    return maxi;
                }
            }
            else{
                if(i-pos >= k){
                    return maxi;
                }
            }
        }
        return maxi;
    }
};
