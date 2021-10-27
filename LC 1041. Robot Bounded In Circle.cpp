class Solution {
public:
    void move(int& x, int& y, char d){
        if(d == 'N'){
            y++;
        }
        if(d == 'W'){
            x--;
        }
        if(d == 'S'){
            y--;
        }
        if(d == 'E'){
            x++;
        }
    }
    
    bool isRobotBounded(string instructions) {
        int x=0, y=0, index = 0;
        int ret = 0;
        vector<char> directions{'N', 'E', 'S', 'W'};
        for(auto i:instructions){
            if(i=='L'){
                ret--;
                if(index==0){
                    index = 4;
                }
                index--;
            }
            else if(i=='R'){
                ret++;
                if(index==3){
                    index = -1;
                }
                index++;
            }
            else{
                move(x, y, directions[index]);
            }
        }
        ret %= 4;
        return ret!=0 || (x==0&&y==0);
    }
};
