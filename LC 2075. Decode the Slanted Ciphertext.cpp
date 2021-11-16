class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ret = "";
        int n = encodedText.size();
        for(int i=0; i<n/rows; i++){
            for(int j=0; j<rows; j++){
                if(j*n/rows+j+i < n){
                    ret += encodedText[j*n/rows+j+i];
                }
            }
        }
        int count = 0;
        for(char i:ret){
            if(i==' '){
                count++;
            }
            else{
                count = 0;
            }
        }
        string ret2 = ret.substr(0, ret.size()-count);
        return ret2;
    }
};
