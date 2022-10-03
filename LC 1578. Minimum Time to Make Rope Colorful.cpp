class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ret = 0, maxi = neededTime[0];
        for(int i=1; i<colors.size(); i++){
            if(colors[i] == colors[i-1]){
                maxi = max(maxi, neededTime[i]);
            }
            else{
                ret += maxi;
                maxi = neededTime[i];
            }
        }
        ret += maxi;
        cout << ret;
        ret = -ret;
        for(int i:neededTime){
            ret += i;
        }
        return ret;
    }
};
