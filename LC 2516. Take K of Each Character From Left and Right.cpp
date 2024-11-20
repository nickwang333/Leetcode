class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<int, int> m;
        int n = s.size(), end = n-1, counter = 0, ret = -1;
        if(k == 0){
            return 0;
        }
        while(end >= 0){
            m[s[end]]++;
            if(m[s[end]] == k){
                counter++;
            }
            if(counter == 3){
                break;
            }
            end--;
        }
        if(counter == 3){
            ret = n-end;
        }
        if(ret == -1){
            return -1;
        }
        for(int i=0; i<n; i++){
            m[s[i]]++;
            while(end < n && m['a'] >= k && m['b'] >= k && m['c']>= k){
                m[s[end]]--;
                end++;
            }
            ret = min(ret, i+1+n-end+1);
        }
        int counter2 = 0;
        unordered_map<int, int> m2;
        for(int i=0; i<n; i++){
            m2[s[i]]++;
            if(m2[s[i]] == k){
                counter2++;
            }
            if(counter2 == 3){
                ret = min(ret, i+1);
            }
        }
        return ret;
    }
};
