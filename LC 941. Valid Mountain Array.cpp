class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3){
            return false;
        }
        int flag = 0;
        for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1]){
                if(flag == 1){
                    return false;
                }
            }
            else if(arr[i]<arr[i-1]){
                if(flag == 0){
                    flag = 1;
                }
                if(i==1){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        
        if(flag == 0){
            return false;
        }
        return true;
    }
};
