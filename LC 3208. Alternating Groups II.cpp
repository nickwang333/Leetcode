class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), count = 0, ret = 0, head = -1;
        for(int i=0; i<n-1; i++){
            int tmp1 = colors[i];
            int tmp2 = colors[i+1];
            if(tmp1 != tmp2){
                count++;
            }
            else{
                count = 0;
            }
            if(count >= k-1){
                ret++;
            }
        }
        count = 0;
        for(int i = n-k+1; i < n+k-2; i++){
            int tmp1 = colors[i % n];
            int tmp2 = colors[(i+1) % n];
            if(tmp1 != tmp2){
                count++;
            }
            else{
                count = 0;
            }
            if(count >= k-1){
                ret++;
            }
        }
        return ret;
    }
};
