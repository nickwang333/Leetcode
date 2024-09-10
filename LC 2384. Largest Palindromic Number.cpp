class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> v(10,0);
        for(char i:num){
            v[i-'0']++;
        }
        string ret = "";
        for(int i=9; i>0; i--){
            int n = v[i];
            for(int j=0; j<n/2; j++){
                ret += ('0' + i);
                v[i]-=2;
            }
        }
        if(ret.size() > 0){
            int n = v[0];
            for(int i=0; i<n/2; i++){
                ret += '0';
                v[0]-=2;
            }
        }

        int flag = 0;
        for(int i=9; i>=0; i--){
            if(v[i] > 0){
                ret += ('0' + i);
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            int n = ret.size();
            for(int i=0; i<n; i++){
                ret += ret[n-i-1];
            }
        }
        else{
            int n = ret.size();
            for(int i=0; i<n-1; i++){
                ret += ret[n-i-2];
            }
        }
        return ret;
    }
};
