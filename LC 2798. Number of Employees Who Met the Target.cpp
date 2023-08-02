class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ret = 0;
        for(auto i:hours){
            if(i >= target)
                ret++;
        }
        return ret;
    }
};
