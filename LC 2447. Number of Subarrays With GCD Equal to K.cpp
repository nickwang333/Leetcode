class Solution {
    int gcd(int a, int b) {
        if (b == 0)
        return a;
        return gcd(b, a % b);
    }

    int composeGCD(queue<int>& q){
        while(q.size() >= 2){
            int tmp1 = q.front();
            q.pop();
            int tmp2 = q.front();
            q.pop();
            q.push(gcd(tmp1, tmp2));
        }
        return q.front();
    }
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size(), ret = 0;
        for(int i=0; i<n; i++){
            queue<int> q;
            for(int j=i; j<n; j++){
                if(nums[j]%k == 0){
                    q.push(nums[j]);
                    composeGCD(q);
                    if(q.front() == k){
                        ret++;
                    }
                }
                else{
                    while(!q.empty()){
                        q.pop();
                    }
                    break;
                }
            }
            
        }
        return ret;
    }
};
