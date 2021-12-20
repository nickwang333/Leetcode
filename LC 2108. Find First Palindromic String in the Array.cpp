class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string i:words){
            string tmp = i;
            reverse(tmp.begin(), tmp.end());
            if(tmp == i){
                return i;
            }
        }
        return "";
    }
};
