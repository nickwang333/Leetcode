class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> left(n), right(n);
        int total = 0;
        for(int i=0; i<n; i++){
            total ^= arr[i];
            left[i] = total;
        }
        total = 0;
        for(int i=n-1; i>=0; i--){
            total ^= arr[i];
            right[i] = total;
        }
        vector<int> ret;
        for(auto i:queries){
            int tmp = total;
            if(i[0] != 0){
                tmp ^= left[i[0]-1];
            }
            if(i[1] != n-1){
                tmp ^= right[i[1]+1];
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
