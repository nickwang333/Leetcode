class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        map<int,int> m;
        for(int i:candies){
            m[i]++;
        }
        int n = m.size(), ret=0;
        for(int i=0; i<candies.size(); i++){
            if(i<k){
                m[candies[i]]--;
                if(m[candies[i]]==0){
                    n--;
                }
                if(i==k-1){
                    ret = n;
                }
            }
            else{
                m[candies[i]]--;
                if(m[candies[i]]==0){
                    n--;
                }
                m[candies[i-k]]++;
                if(m[candies[i-k]]==1){
                    n++;
                }
                ret = max(ret, n);
            }
        }
        return max(ret,n);
    }
};
