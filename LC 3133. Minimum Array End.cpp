class Solution {
public:
    long long minEnd(int n, int x) {
        long long ret = 0;
        n--;
        string sx = "", sn = "";
        int counter = 0;
        while(n > 0){
            sn += (n%2 + '0');
            n /= 2;
        }
        while(x > 0){
            sx += (x%2 + '0');
            x /= 2;
        }
        for(int i=0; i<sx.size(); i++){
            if(counter == sn.size()){
                break;
            }
            if(sx[i] == '0'){
                sx[i] = sn[counter];
                counter++;
            }
        }
        for(int i=counter; i<sn.size(); i++){
            sx += sn[i];
        }
        for(int i=0; i<sx.size(); i++){
            ret += (pow(2,i)) * (sx[i]-'0');
        }
        return ret;
    }
};
