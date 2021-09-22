class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), high=nums[0];
        if(n==1){
            return 0;
        }
        vector<int> v(n+1,-1);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=i+nums[i]; j++){
                if(i==0){
                    v[j] = 1;
                    if(j>=n){
                        return 1;
                    }
                }
                else{
                    if(v[j]==-1){
                        v[j] = v[i]+1;
                    }
                    else{
                        v[j] = min(v[j], v[i]+1);
                    }
                    if(j>=n){
                        v[j] = min(v[j], v[i]+1);
                        break;
                    }
                }
            }
        }
        return v[n-1];
    }
};
