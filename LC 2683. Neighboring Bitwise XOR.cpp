class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        if(derived.size() == 1){
            if(derived[0] == 0){
                return true;
            }
            else{
                return false;
            }
        }
        int ret = -1;
        for(int i:derived){
            if(ret == -1){
                ret = i;
            }
            else{
                ret ^= i;
            }
        }
        return ret == 0;
    }
};
