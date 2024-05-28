class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), total = 0, pointer = 0, ret = 0;
        vector<int> diff(n);
        for(int i=0; i<n; i++){
            diff[i] = abs(s[i] - t[i]);
        }
        for(int i=0; i<n; i++){
            total += diff[i];
            while(pointer < i && total > maxCost){
                total -= diff[pointer];
                pointer++;
            }
            if(pointer == i && diff[i] > maxCost){
                continue;
            }
            ret = max(ret, i-pointer+1);
        }
        return ret;
    }
};
