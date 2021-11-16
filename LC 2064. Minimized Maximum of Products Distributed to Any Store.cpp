class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = 100000, mid;
        while(low<high){
            mid = (low+high)/2;
            int tmp = 0;
            for(int i:quantities){
                tmp += ((i-1)/mid)+1;
            }
            if(tmp>n){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};
