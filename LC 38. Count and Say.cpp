class Solution {
public:
    string countAndSay(int n) {
        string ret = "1", tmp;
        for(int i=2; i<=n; i++){
            int counter = 1;
            char digit = ret[0];
            tmp = "";
            for(int j=1; j<ret.size(); j++){
                if(ret[j]==ret[j-1]){
                    counter++;
                }
                else{
                    tmp +=to_string(counter);
                    tmp +=digit;
                    counter = 1;
                    digit = ret[j];
                }
            }
            tmp +=to_string(counter);
            tmp +=digit;
            ret = tmp;
        }
        return ret;
    }
};
