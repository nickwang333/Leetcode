class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int fp = 0, sp = plants.size()-1, ret = 0, a = capacityA, b = capacityB;
        while(fp<=sp){
            if(fp == sp){
                if(a>=plants[fp] || b>=plants[fp]){
                    return ret;
                }
                return ret+1;
            }
            if(plants[fp]<=a){
                a -= plants[fp];
                fp++;
            }
            else if(plants[fp]<=capacityA){
                ret++;
                a = capacityA - plants[fp];
                fp++;
            }
            if(plants[sp]<=b){
                b -= plants[sp];
                sp--;
            }
            else if(plants[sp]<=capacityB){
                ret++;
                b = capacityB - plants[sp];
                sp--;
            }
            
        }
        return ret;
    }
};
