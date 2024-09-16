class Solution {
public:
    string losingPlayer(int x, int y) {
        int tmpy = y/4;
        int mini = min(x, tmpy);
        if(mini % 2 == 0){
            return "Bob";
        }
        return "Alice";
    }
};
