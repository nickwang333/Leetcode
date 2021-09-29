class Solution {
public:
    int shortestWay(string source, string target) {
        map<char, vector<int>> m;
        int n = target.size();
        vector<int> v(n,0);
        for(int i=0; i<source.size(); i++){
            m[source[i]].push_back(i);
        }
        int hold = 0;
        for(int i=0; i<n; i++){
            if(m[target[i]].size()==0){
                return -1;
            }
            if(i==0){
                v[i] = 1;
                hold = m[target[i]][0];
            }
            else{
                auto it = upper_bound(m[target[i]].begin(), m[target[i]].end(), hold);
                if(it==m[target[i]].end()){
                    v[i] = v[i-1]+1;
                    hold = m[target[i]][0];
                }
                else{
                    hold = *it;
                    v[i] = v[i-1];
                }
            }
        }
        return v[n-1];
    }
};
