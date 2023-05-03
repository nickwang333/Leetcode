class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), tmp = 0;
        unordered_map<int, int> m;
        vector<int> ret(n);
        for(int i=0; i<n; i++){
            m[A[i]]++;
            m[B[i]]++;
            if(A[i] != B[i]){
                if(m[A[i]] == 2){
                    tmp++;
                }
                if(m[B[i]] == 2){
                    tmp++;
                }
            }
            else{
                tmp++;
            }
            ret[i] = tmp;
        }
        return ret;
    }
};
