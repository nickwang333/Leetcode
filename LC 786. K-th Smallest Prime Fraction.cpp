class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<double> maxq;
        unordered_map<double, vector<int>> m;

        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                double tmp1 = -double(arr[i]) / double(arr[j]);
                maxq.push(tmp1);
                m[tmp1] = (vector<int>{arr[i], arr[j]});
            }
        }
        
        priority_queue<double> maxq2 = maxq;
        
        for(int i=0; i<k-1; i++){
            maxq.pop();
        }
        return m[maxq.top()];
    }
};
