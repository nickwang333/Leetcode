class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1);
        ret[0] = 1;
        int prev, curr;
        for(int i=0; i<rowIndex; i++){
            ret[i+1] = 1;
            prev = 1, curr = 1;
            for(int j=1; j<=i; j++){
                curr = prev;
                prev = ret[j];
                ret[j] = ret[j]+curr;
            }
        }
        return ret;
    }
};
