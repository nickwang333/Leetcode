class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ret = 0;
        int n = costs.size(), i1 = candidates, i2 = n-candidates-1;
        priority_queue<int> q1, q2;
        for(int i=0; i<candidates; i++){
            q1.push(-costs[i]);
        }
        for(int i=n-candidates; i<n; i++){
            if(i >= i1){
                q2.push(-costs[i]);
            }
        }
        for(int i=0; i<k; i++){
            int tmp1 = INT_MIN, tmp2 = INT_MIN;
            if(!q1.empty()){
                tmp1 = q1.top();
            }
            if(!q2.empty()){
                tmp2 = q2.top();
            }
            if(i2 >= i1){
                if(tmp2 > tmp1){
                    ret -= tmp2;
                    q2.pop();
                    q2.push(-costs[i2]);
                    i2--;
                }
                else{
                    ret -= tmp1;
                    q1.pop();
                    q1.push(-costs[i1]);
                    i1++;
                }
            }
            else{
                if(tmp2 > tmp1){
                    ret -= tmp2;
                    q2.pop();
                }
                else{
                    ret -= tmp1;
                    q1.pop();
                }
            }
            cout << ret << " ";
        }
        return ret;
    }
};
