class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int count = 0;
        string ret1, ret2;
        for(int i=S.size()-1; i>=0; i--){
            if(S[i]=='#'){
                count++;
            }
            else{
                if(count==0){
                    ret1 +=  S[i];
                }
                else{
                    count--;
                }
            }
        }
        count = 0;
        for(int i=T.size()-1; i>=0; i--){
            if(T[i]=='#'){
                count++;
            }
            else{
                if(count==0){
                    ret2 +=  T[i];
                }
                else{
                    count--;
                }
            }
        }
        return ret1 == ret2;
    }
};
