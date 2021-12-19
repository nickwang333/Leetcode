class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size(), sp = 0;
        string ret = "";
        for(int i=0; i<n; i++){
            if(sp==-1){
                ret += s[i];
            }
            else if(spaces[sp] == i){
                ret += " ";
                ret += s[i];
                sp++;
                if(sp == spaces.size()){
                    sp = -1;
                }
            }
            else{
                ret += s[i];
            }
        }
        return ret;
    }
};
