class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0, n = colors.size();
        vector<int> v(n,0), v2(n,0);
        for(int i=0; i<n; i++){
            if(i==0){
                if(colors[i] == 'A'){
                    v[i] = 1;    
                }
                else{
                    v2[i] = 1;
                }
            }
            else{
                if(colors[i] == 'A'){
                    v[i] = v[i-1]+1;    
                    if(v[i] >= 3){
                        a++;
                    }
                }
                else{
                    v2[i] = v2[i-1]+1;
                    if(v2[i]>=3){
                        b++;
                    }
                }
            }
        }
        return a>b;
    }
};
