class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ret;
        for(int i=2; i<n; i++){
            if(num[i] == num[i-1] && num[i-1] == num[i-2]){
                string tmp = num.substr(i-2, 3);
                if(ret == ""){
                    ret = num.substr(i-2, 3);
                }
                if(ret < tmp){
                    ret = tmp;
                }
            }
        }
        return ret;
    }
};
