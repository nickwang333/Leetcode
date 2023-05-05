class Solution {
public:
    int maxVowels(string s, int k) {
        queue<char> q;
        int ret = 0, tmp = 0;
        for(char i:s){
            if(q.size() < k){
                q.push(i);
                if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
                    tmp++;
                    ret = max(ret, tmp);
                }
            }
            else{
                char tmpc = q.front();
                if(tmpc == 'a' || tmpc == 'e' || tmpc == 'i' || tmpc == 'o' || tmpc == 'u'){
                    tmp--;
                }
                if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
                    tmp++;
                    ret = max(ret, tmp);
                }
                q.pop();
                q.push(i);
            }
        }
        return ret;
    }
};
