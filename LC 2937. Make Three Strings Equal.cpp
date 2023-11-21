class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size(), index = min(sz1, min(sz2, sz3));
        for(int i=0; i<min(sz1, min(sz2, sz3)); i++){
            if(s1[i] == s2[i] && s2[i] == s3[i]){
                continue;
            }
            else{
                index = i;
                break;
            }
        }
        if(index < 1){
            return -1;
        }
        return (sz1 + sz2 + sz3) - index*3;
    }
};
