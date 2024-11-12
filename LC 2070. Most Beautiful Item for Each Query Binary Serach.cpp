bool compareByAge(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
}

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ret = queries;
        items.push_back(vector<int>{0, 0});
        sort(items.begin(), items.end(), compareByAge);
        for(int i=1; i<items.size(); i++){
            items[i][1] = max(items[i-1][1], items[i][1]);
        }
        for(int i=0; i<queries.size(); i++){
            int tmp = -1;
            int high = items.size()-1, low = 0, mid;
            while(high > low){
                mid = (high+low+1)/2;
                if(items[mid][0] > queries[i]){
                    high = mid-1;
                }
                else{
                    low = mid;
                }
            }
            ret[i] = items[low][1];
        }
        return ret;
    }
};
