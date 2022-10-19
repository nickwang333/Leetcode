class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> v(n,0);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            v[tmp] = 1;
            if(((tmp+arr[tmp]) < n) && v[tmp+arr[tmp]] == 0){
                q.push(tmp+arr[tmp]);
                v[tmp+arr[tmp]] = 1;
            }
            if(((tmp-arr[tmp]) >= 0) && v[tmp-arr[tmp]] == 0){
                q.push(tmp-arr[tmp]);
                v[tmp-arr[tmp]] = 1;
            }
        }
        for(int i=0; i<n; i++){
            cout << v[i] << " ";
        }

        for(int i=0; i<n; i++){
            if(arr[i] == 0 && v[i] == 1){
                return true;
            }
        }
        return false;
    }
};
