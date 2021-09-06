class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        long tmp = releaseTimes[0];
        char ret = keysPressed[0];
        for(int i=1; i<releaseTimes.size(); i++){
            long curr = releaseTimes[i]-releaseTimes[i-1];
            if(curr>tmp){
                ret = keysPressed[i];
                tmp = curr;
            }
            else if(curr == tmp){
                if(keysPressed[i] > ret){
                    ret = keysPressed[i];
                }
            }
        }
        return ret;
    }
};
