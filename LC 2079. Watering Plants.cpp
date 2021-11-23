class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ret = 0, w = capacity;
        for(int i=0; i<plants.size(); i++){
            if(w>=plants[i]){
                w -= plants[i];
                ret++;
            }
            else{
                w = capacity - plants[i];
                ret += (i)*2+1;
            }
        }
        return ret;
    }
};
