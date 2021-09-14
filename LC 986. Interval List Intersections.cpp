class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ret;
        int sp = 0, fp = 0, n = A.size(), m = B.size();
        while(fp<n && sp<m){
            vector<int> tmp(2);
            if(A[fp][1] >= B[sp][0] && B[sp][0] >= A[fp][0]){
                tmp[0] = max(A[fp][0], B[sp][0]);
                tmp[1] = min(A[fp][1], B[sp][1]);
                ret.push_back(tmp);
            }
            else if(B[sp][1] >= A[fp][0] && A[fp][0] >= B[sp][0]){
                tmp[0] = max(A[fp][0], B[sp][0]);
                tmp[1] = min(A[fp][1], B[sp][1]);
                ret.push_back(tmp);
            }
            if(fp==n-1){
                sp++;
            }
            else if(sp==m-1){
                fp++;
            }
            else if(A[fp][1] < B[sp][1]){
                fp++;
            }
            else{
                sp++;
            }
        }
        return ret;
    }
};
