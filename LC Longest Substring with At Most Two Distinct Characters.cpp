class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int first = 0, second = 0, ret = 1;
        char one = s[0], two = ' ';
        map<char,int> m;
        while(first < s.size()){
            if(s[first] == one || s[first] == two){
                ret = max(ret, first - second + 1);
                m[s[first]]++;
                first++;
                continue;
            }
            else if(two == ' '){
                ret = max(ret, first - second + 1);
                two = s[first];
                m[s[first]]++;
                first++;
            }
            else{
                char removed = ' ';
                if(s[first-1] == one){
                    removed = two;
                    two = s[first];
                }
                else{
                    removed = one;
                    one = two;
                    two = s[first];
                }
                m[s[first]]++;
                first++;
                while(second < first && m[removed] != 0){
                    m[s[second]]--;
                    second++;
                }
                
            }
        }
        return ret;
    }
};
