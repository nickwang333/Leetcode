class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size(), prev = 0;
        sort(arr.begin(), arr.end());
        for(int i:arr){
            if(i - prev > 1){
                prev = prev+1;
            }
            else{
                prev = i;
            }
        }
        return prev;
    }
};
