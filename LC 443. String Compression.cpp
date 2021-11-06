class Solution {
public:
    int compress(vector<char>& chars) {
        char tmp = chars[0];
        int size = 0, len = 1;
        for(int i=1; i<chars.size(); i++){
            if(chars[i] != tmp){
                chars[size] = tmp;
                size++;
                if(len!=1){
                    string tmp2 = to_string(len);
                    for(int j=0; j<tmp2.size(); j++){
                        chars[size] = tmp2[j];
                        size++;
                    }
                }
                len = 0;
                tmp = chars[i];
            }
            len++;
        }
        chars[size] = tmp;
        size++;
        if(len!=1){
            string tmp2 = to_string(len);
            for(int j=0; j<tmp2.size(); j++){
                chars[size] = tmp2[j];
                size++;
            }
        }
        return size;
    }
};
