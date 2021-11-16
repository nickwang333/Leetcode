class Robot {
public:
    int x, y, w, h, ori;
    string dir;
    
    Robot(int width, int height) {
        dir = "East";
        w = width;
        h = height;
        ori = 0;
        x = 0;
        y = 0;
    }
    
    int remain(){
        int ret;
        if(dir == "East"){
            ret = w-x-1;
        }
        else if(dir == "West"){
            ret = x;
        }
        else if(dir == "North"){
            ret = h-y-1;
        }
        else{
            ret = y;
        }
        return ret;
    }
    
    void updatedir(){
        if(dir == "East"){
            dir = "North";
        }
        else if(dir == "West"){
            dir = "South";
        }
        else if(dir == "North"){
            dir = "West";
        }
        else{
            dir = "East";
        }
    }
    
    void moved(int dis){
       if(dir == "East"){
            x += dis;
        }
        else if(dir == "West"){
            x -= dis;
        }
        else if(dir == "North"){
            y += dis;
        }
        else{
            y -= dis;
        } 
    }
    
    void move(int num) {
        ori = 1;
        int last = remain();
        num %= (2*w + 2*h -4);
        while(num>0){
            if(num>=last){
                moved(last);
                updatedir();
            }
            else{
                moved(num);
                break;
            }
            num -= last;
            last = remain();
        }
    }
    
    vector<int> getPos() {
        vector<int> ret(2);
        ret[0] = x;
        ret[1] = y;
        return ret;
    }
    
    string getDir() {
        if(ori == 0){
            return dir;
        }
        if(x == 0 && y == 0){
            return "South";
        }
        else if(x == w-1 && y == 0){
            return "East";
        }
        else if(x == w-1 && y == h-1){
            return "North";
        }
        else if(x == 0 && y == h-1){
            return "West";
        }
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
