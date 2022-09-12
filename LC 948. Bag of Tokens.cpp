class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        long ret = 0, points = 0, tmp = power, front = 0, end = tokens.size()-1;
        while(front <= end && (power >= tokens[front] || points>0)){
            while(front <= end && tokens[front] <= power){
                power -= tokens[front];
                front++;
                points++;
            }
            ret = max(ret, points);
            if(front<=end && points > 0){
                points--;
                power += tokens[end];
                end--;
            }
        }
        
        return ret;
    }
};
