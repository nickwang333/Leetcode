/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int a = 0, b = 1;
        while(b!=n){
            if(knows(a,b)){
                a = b;
                b++;
            }
            else{
                b++;
            }
        }
        if(a == n){
            return -1;
        }
        for(int i=0; i<n; i++){
            if(i!=a){
                if(knows(a,i) || !knows(i,a)){
                    return -1;
                }
            }
        }
        return a;
    }
};
