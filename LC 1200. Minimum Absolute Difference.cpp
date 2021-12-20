class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ret;
        int diff = arr[1] - arr[0];
        for(int i=2; i<n; i++){
            diff = min(diff, arr[i]-arr[i-1]);
        }
        for(int i=1; i<n; i++){
            if(arr[i]-arr[i-1] == diff){
                vector<int> v(2);
                v[0] = arr[i-1];
                v[1] = arr[i];
                ret.push_back(v);
            }
        }
        return ret;
    }
};
