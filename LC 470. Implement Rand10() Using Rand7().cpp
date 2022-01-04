// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int i = rand7(), j = rand7();
        while(((i-1)*7+j-1)>=40){
            i = rand7();
            j = rand7();
        }
        return ((i-1)*7+j-1)%10+1;
    }
};
