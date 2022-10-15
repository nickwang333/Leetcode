class Solution {
    string findMin(string tmp){
        int tmp1 = stoi(tmp, nullptr, 16);
        int result = -1;
        string ret;
        string d = "0123456789abcdef";
        for(int i=0; i<16; i++){
            
            int tmp2 = i*16+i;
            if(result == -1){
                result = abs(tmp2-tmp1);
                ret = d[i];
                ret += d[i];
                
            }
            else if(result > abs(tmp2-tmp1)){
                result = abs(tmp2-tmp1);
                ret = d[i];
                ret += d[i];
            }
        }
        return ret;
    }
public:
    string similarRGB(string color) {
        string ret = "#";
        ret += findMin(color.substr(1,2));
        ret += findMin(color.substr(3,2));
        ret += findMin(color.substr(5,2));
        return ret;
    }
};
