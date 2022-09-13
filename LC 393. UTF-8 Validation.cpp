class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for(int i=0; i<data.size(); i++){
            if(data[i] < 128){
                continue;
            }
            else if(data[i] >= 192 && data[i] < 224){
                if(i >= n-1 || data[i+1] < 128 || data[i+1] > 191){
                    return false;
                }
                i++;
            }
            else if(data[i] >= 224 && data[i] < 240){
                if(i >= n-2 || data[i+1] < 128 || data[i+1] > 191
                  || data[i+2] <128 || data[i+2] > 191){
                    return false;
                }
                i += 2;
            }
            else if(data[i] >= 240 && data[i] < 248){
                if(i >= n-3 || data[i+1] > 191
                  || data[i+2] <128 || data[i+2] > 191
                  || data[i+3] <128 || data[i+3] > 191){
                    return false;
                }
                i += 3;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
