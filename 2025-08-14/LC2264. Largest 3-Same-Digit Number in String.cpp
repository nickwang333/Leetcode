class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ret = "";
        for(int i=0; i<n-2; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                if(ret == "" || num[i] > ret[0]){
                    ret = num.substr(i, 3);
                }
            }
        }
        return ret;
    }
};
