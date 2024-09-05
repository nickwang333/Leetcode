class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
        map<vector<int>, int> m;
        int ret = 0;
        for(auto i:obstacles){
            m[i] = 1;
        }
        vector<int> v{0, 0};
        
        int x = 0, y = 0, d = 0;
        for(int i:commands){
            if(i == -1){
                d++;
                d%=4;
            }
            else if(i == -2){
                d+=4;
                d--;
                d%=4;
            }
            else{
                for(int j=0; j<i; j++){
                    vector<int> tmp{x+dx[d], y+dy[d]};
                    if(m[tmp] == 1){
                        break;
                    }
                    x += dx[d];
                    y += dy[d];
                    ret = max(ret, x*x + y*y);
                }
            }
        }
        return  ret;
    }
};
