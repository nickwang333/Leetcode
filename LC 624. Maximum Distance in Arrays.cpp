class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size(), max1 = INT_MIN, max2 = max1;
        int min1 = INT_MAX, min2 = min1, posmin = 0, posmax = 0;
        int countermax = 1, countermin = 1;
        for(int i=0; i<n; i++){
            int sz = arrays[i].size(), begin = arrays[i][0], end = arrays[i][sz-1];
            if(begin < min1){
                min2 = min1;
                min1 = begin;
                posmin = i;
                countermin = 1;
            }
            else if(begin == min1){
                countermin++;
            }
            else if(min2 > begin){
                min2 = begin;
            }
            if(end > max1){
                max2 = max1;
                max1 = end;
                posmax = i;
                countermax = 1;
            }
            else if(end == max1){
                countermax++;
            }
            else if(max2 < end){
                max2 = end;
            }
        }
        if(posmax == posmin && countermax == 1 && countermin == 1){
            return max(max1-min2, max2-min1);
        }
        return max1 - min1;
    }
};
