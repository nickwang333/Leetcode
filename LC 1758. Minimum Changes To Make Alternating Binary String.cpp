class Solution {
public:
    int minOperations(string s) {
        int n1 = 0, n2 = 0;
        for(int i=0; i<s.size(); i++){
            if(i%2 == 0){
                if(s[i] == '0'){
                    n1++;
                }
                else{
                    n2++;
                }
            }
            else{
                if(s[i] == '0'){
                    n2++;
                }
                else{
                    n1++;
                }
            }
        }
        return min(n1, n2);
    }
};
