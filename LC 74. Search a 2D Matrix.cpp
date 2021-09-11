class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int high = n-1, low = 0;
        while(low < high){
            int mid = (low+high)/2;
            if(matrix[mid][0] > target){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(low > 0 && matrix[low][0] > target){
            low--;
        }
        int high2 = m-1, low2 = 0;
        while(low2 < high2){
            int mid = (low2+high2)/2;
            if(matrix[low][mid] < target){
                low2 = mid+1;
            }
            else{
                high2 = mid;
            }
        }
        //cout << matrix[low][low2];
        return matrix[low][low2] == target;
    }
};
