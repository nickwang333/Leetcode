class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0; i<m; i++){
            if(matrix[i][0]>target){
                return false;
            }
            int low = 0, high = n-1, mid;
            while(high>low){
                mid = low+(high-low)/2;
                if(matrix[i][mid]<target){
                    low = mid+1;
                }
                else{
                    high = mid;
                }
            }
            cout << matrix[i][low];
            if(matrix[i][low]==target){
                return true;
            }
        }
        
        return false;
    }
};
