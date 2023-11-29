class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size(), counter1 = 0, counter2 = 0, ret = 0;
        vector<int> v(n, 0), v2(n,0);
        for(int i=0; i<n; i++){
            counter1 = 0;
            counter2 = 0;
            for(int j=i; j<n; j++){
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                    counter1++;
                }
                else{
                    counter2++;
                }
                if(counter1 == counter2 && counter1*counter2%k == 0){
                    ret++;
                }
            }
        }
        return ret;
    }
};
