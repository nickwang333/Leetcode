class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ret = 0, flag = 1;
        map<string, int> m;
        for(string i:words){
            m[i]++;
        }
        for(auto it = m.begin(); it!=m.end(); it++){
            string tmp = it->first;
            reverse(tmp.begin(), tmp.end());
            if(tmp == it->first){
               if(flag == 1){
                   if(it->second%2==1){
                       flag = 0;
                       ret += (it->second*2);
                   }
                   else{
                       ret += (it->second*2);
                   }
                }
                else{
                    ret += (it->second - it->second%2)*2;
                }
            }
            else{
                if(m[tmp] != 0){
                    int tmp2 = min(m[tmp], it->second);
                    ret += (tmp2*4);
                    m[tmp] -= tmp2;
                    it->second -= tmp2;
                }
            }
        }
        return ret;
    }
};
