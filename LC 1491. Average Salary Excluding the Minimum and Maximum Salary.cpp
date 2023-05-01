class Solution {
public:
    double average(vector<int>& salary) {
        double n = salary.size(), ret = 0;
        int maxi = salary[0], mini = salary[0];
        for(int i:salary){
            mini = min(i, mini);
            maxi = max(i, maxi);
            ret += i;
        }
        ret -= maxi;
        ret -= mini;
        ret /= (n-2);
        return ret;
    }
};
