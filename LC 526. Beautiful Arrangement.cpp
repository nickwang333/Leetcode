class Solution {
public:
    int countArrangement(int n) {
        int ret = 0;
        queue<vector<int>> q;
        vector<int> v{0};
        q.push(v);
        while(!q.empty()){
            int sz = q.size();
            for(int j=0; j<sz; j++){
                auto tmp = q.front();
                q.pop();
                if(tmp.size() == n+1){
                    ret++;
                    break;
                }
                for(int i=1; i<=n; i++){
                    int exist = 0;
                    for(int in:tmp){
                        if(in == i){
                            exist = 1;
                        }
                    }
                    int sz2 = tmp.size();
                    if(exist == 0 && (i%sz2 == 0 || sz2 % i == 0)){
                        vector<int> v2 = tmp;
                        v2.push_back(i);
                        q.push(v2);
                    }
                }
            }
        }
        return ret;
    }
};
