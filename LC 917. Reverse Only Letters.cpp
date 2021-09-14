class Solution {
public:
    string reverseOnlyLetters(string s) {
        int low = 0, high = s.size()-1;
        while(low < high){
            while(low<high && !isalpha(s[low])){
                low++;
            }
            while(high>low && !isalpha(s[high])){
                high--;
            }
            char tmp = s[high];
            s[high] = s[low];
            s[low] = tmp;
            high--;
            low++;
        }
        return s;
    }
};
