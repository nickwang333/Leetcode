class Solution {
public:
    string removeTrailingZeros(string num) {
        int start_i = 0, end_i = num.size()-1, n = num.size();
        string ret;
        while(start_i < n && num[start_i] == '0'){
            start_i++;
        }
        while(end_i >= 0 && num[end_i] == '0'){
            end_i--;
        }
        for(int i=start_i; i <= end_i; i++){
            ret += num[i];
        }
        return ret;
    }
};
