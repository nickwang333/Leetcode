class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), begin = 0, end = n-1, ret = 1;
        vector<int> v;
        while(end > 0 && arr[end] >= arr[end-1]){
            end--;
        }
        while(begin < n-1 && arr[begin] <= arr[begin+1]){
            begin++;
        }
        ret = max(ret, n-end);
        ret = max(ret, begin+1);
        int pointer = end;
        if(begin > end || n == 1){
            return 0;
        }
        for(int i=0; i<=begin; i++){
            while(pointer < n && arr[pointer] < arr[i]){
                pointer++;
            }
            ret = max(ret, i+1 + n-pointer);
        }
        return n-ret;
    }
};
