class Solution {
public:
    int findMINI(vector<int>& v){
        int ret = 0, val = v[0], n = v.size();
        for(int i=0; i<n; i++){
            if(v[i] < val){
                val = v[i];
                ret = i;
            }
        }
        return ret;
    }

    vector<int> removeMINI(vector<int>& v, int pos){
        vector<int> ret;
        for(int i=0; i<v.size(); i++){
            if(i != pos){
                ret.push_back(v[i]);
            }
        }
        return ret;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size(), ret = 0;
        for(int i=0; i<n-1; i++){
            int pos = findMINI(arr);
            int tmp = INT_MAX;
            if(pos > 0){
                tmp = arr[pos-1];
            }
            if(pos < arr.size()-1){
                tmp = min(tmp, arr[pos+1]);
            }
            ret += (tmp*arr[pos]);
            arr = removeMINI(arr, pos);
        }
        
        return ret;
    }
};
