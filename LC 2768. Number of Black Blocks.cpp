class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> ret(5,0);
        unordered_map<long long, long long> m2;
        for(auto i:coordinates){
            // check 4 coordinates: i>0, j>0; i>0; 
            long tmp2 = max(m,n);
            if(i[0] > 0 && i[1] > 0){
                long long tmp = long((i[0]-1))* tmp2+ (i[1]-1);
                m2[tmp]++;
            }
            if(i[0] > 0 && i[1] != n-1){
                long long tmp = (i[0]-1)* tmp2+ (i[1]);
                m2[tmp]++;
            }
            if(i[1] > 0 && i[0] != m-1){
                long long tmp = (i[0])* tmp2 + (i[1]-1);
                m2[tmp]++;
            }
            if(i[0] != m-1 && i[1] != n-1){
                long long tmp = (i[0])* tmp2 + (i[1]);
                m2[tmp]++;
            }
        }
        for(auto i:m2){
            ret[i.second]++;
        }
        ret[0] = long(m-1)*long(n-1) - ret[1] - ret[2] - ret[3] - ret[4];
        return ret;
    }
};
