class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size(), ret = 1;
        vector<bool> used(n,false);
        int diff = 0;
        if(start == end){
            return 0;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            diff = 0;
            for(int j=0; j<8; j++){
                if(bank[i][j] != start[j]){
                    diff++;
                }
            }
            if(diff == 1){
                q.push(i);
                used[i] = true;
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int tmp = q.front();
                q.pop();
                if(bank[tmp] == end){
                    return ret;
                }
                for(int j=0; j<n; j++){
                    diff = 0;
                    if(!used[j]){
                        for(int z=0; z<8; z++){
                            if(bank[j][z] != bank[tmp][z]){
                                diff++;
                            }
                        }
                        if(diff == 1){
                            q.push(j);
                            used[j] = true;
                        }
                    }
                }
            }
            ret++;
        }
        return -1;
    }
};
