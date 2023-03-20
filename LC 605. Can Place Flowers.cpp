class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size(), maxi = 0;
        vector<int> count(sz, 0);
        for(int i=0; i<sz; i++){
            if(flowerbed[i] == 0){
                if(i == 0){
                    count[i] = 2;
                }
                else{
                    count[i] = count[i-1]+1;
                }
            }
            else{
                if(i != 0 && count[i-1] != 0){
                    maxi += ((count[i-1]-1)/2);
                }
            }
        }
        cout << maxi << endl;
        maxi += ((count[sz-1])/2);
        cout << maxi;
        return maxi >= n;
    }
};
