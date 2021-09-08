/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */
int find_first_one(BinaryMatrix &b, int row, int col){
    int low = 0, high = col-1, val, mid;
    while(low < high){
        mid = (low+high)/2;
        val = b.get(row, mid);
        if(val==0){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    if(b.get(row,low)==1){
        return low;
    }
    return -1;
}

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> first_one;
        vector<int> v = binaryMatrix.dimensions();
        int row = v[0], col = v[1];
        for(int i=0; i<row; i++){
            first_one.push_back(find_first_one(binaryMatrix, i, col));
        }
        sort(first_one.begin(), first_one.end());
        for(int i=0; i<first_one.size()-1; i++){
            if(first_one[i]==first_one[i+1] || first_one[i]== -1 ){
                continue;
            }
            return first_one[i];
        }
        return first_one[col-1];
    }
};
