class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = 0, j = 0;
        if(s.size() == 1){
            return -1;
        }
        for(i=s.size()-2; i>=0; i--){
            if(s[i] < s[i+1]){
                break;
            }
        }
        if(i==-1){
            return -1;
        }
        for(j = s.size()-1; j>i; j--){
            if(s[j] > s[i]){
                swap(s[j], s[i]);
                reverse(s.begin()+i+1, s.end());
                if(s.size()<10 || s<="2147483647"){
                    return stoi(s);
                }
                else{
                    return -1;
                }
            }
        }
        return -1;
    }
};
