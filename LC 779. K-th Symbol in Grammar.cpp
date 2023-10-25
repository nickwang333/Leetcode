class Solution {
public:
    int kthGrammar(int n, int k) {
        int counter = 0;
        for(int i=30; i>=0; i--){
            int tmp = pow(2, i);
            if(k > tmp){
                k -= tmp;
                counter++;
            }
        }
        return counter%2;
    }
};
