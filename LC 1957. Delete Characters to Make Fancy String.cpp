class Solution {
public:
    string makeFancyString(string s) {
        string ret = "";
        ret += s[0];
        int counter = 1;
        int n = s.size();
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                counter++;
                if(counter < 3){
                    ret += s[i];
                }
            }
            else{
                counter = 1;
                ret += s[i];
            }
        }
        return ret;
    }
};
