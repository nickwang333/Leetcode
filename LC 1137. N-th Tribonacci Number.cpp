class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return 1;
        }
        else if(n == 2){
            return 1;
        }
        int one = 0, two = 1, three = 1;
        for(int i=0; i<n-2; i++){
            int tmp = one + two + three;
            one = two;
            two = three;
            three = tmp;
        }
        return three;
    }
};
