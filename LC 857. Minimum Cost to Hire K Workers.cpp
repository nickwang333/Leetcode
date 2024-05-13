class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size(), total = 0;
        double ret = numeric_limits<double>::max();
        vector<pair<double, int>> v;
        for(int i=0; i<n; i++){
            v.push_back(pair<double, int>{double(wage[i]) / double(quality[i]), quality[i]});
        }
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            pq.push(v[i].second);
            total += v[i].second;

            if(pq.size() > k){
                total -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k){
                ret = min(ret, total * v[i].first);
            }
        }
        return ret;
    }
};
