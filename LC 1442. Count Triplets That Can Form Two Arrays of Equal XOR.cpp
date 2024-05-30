class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), ret = 0;
        for(int i=0; i<n-1; i++){
            unordered_map<int, int> m;
            int tmp = arr[i];
            m[tmp]++;
            for(int j=i-1; j>=0; j--){
                tmp ^= arr[j];
                m[tmp]++;
            }
            tmp = arr[i+1];
            ret += m[tmp];
            for(int j=i+2; j<n; j++){
                tmp ^= arr[j];
                ret += m[tmp];
            }
        }
        return ret;
    }
};
