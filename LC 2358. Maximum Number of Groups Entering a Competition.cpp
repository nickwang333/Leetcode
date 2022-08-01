class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int ret = 0, tsum = 0;
        while(tsum <= grades.size()){
            tsum += ret;
            tsum += 1;
            ret++;
        }
        return ret-1;
    }
};
