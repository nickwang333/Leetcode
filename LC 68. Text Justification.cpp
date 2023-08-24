class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        queue<string> q;
        int count = 0, len = 0;
        for(string i:words){
            if((len+count+i.size()) > maxWidth){
                string tmp = "";
                int tmp2 = maxWidth;
                count--;
                while(q.size() > 1){
                    tmp += q.front();
                    int space = (tmp2 - len)/count;
                    if((tmp2-len)%count != 0){
                        space++;
                    }
                    for(int i=0; i<space; i++){
                        tmp += " ";
                    }
                    tmp2 -= space;
                    tmp2 -= q.front().size();
                    len -= q.front().size();
                    q.pop();
                    count--;
                }
                tmp += q.front();
                q.pop();
                q.push(i);
                len = i.size();
                count = 1;
                for(int j=tmp.size(); j<maxWidth; j++){
                    tmp += " ";
                }
                ret.push_back(tmp);
            }
            else{
                q.push(i);
                count++;
                len += i.size();
            }
        }
        string tmp = "";
        while(q.size() > 1){
            tmp += q.front();
            tmp += " ";
            q.pop();
        }
        tmp += q.front();
        for(int j=tmp.size(); j<maxWidth; j++){
            tmp += " ";
        }
        ret.push_back(tmp);
        return ret;
    }
};
