class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long ret = 0;
        int n = enemyEnergies.size();
        sort(enemyEnergies.begin(), enemyEnergies.end());
        long long total = currentEnergy;
        if(enemyEnergies[0] > currentEnergy){
            return 0;
        }
        for(int i=1; i<enemyEnergies.size(); i++){
            total += enemyEnergies[i];
        }
        ret = total / enemyEnergies[0];
        return ret;
    }
};
