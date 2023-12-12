class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ret = 0, count = 0;
        for(int i=0; i<batteryPercentages.size(); i++){
            if(batteryPercentages[i]-count > 0){
                count++;
                ret++;
            }
        }
        return ret;
    }
};
