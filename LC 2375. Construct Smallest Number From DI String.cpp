class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        queue<string> q;
        q.push("1");
        q.push("2");
        q.push("3");
        q.push("4");
        q.push("5");
        q.push("6");
        q.push("7");
        q.push("8");
        q.push("9");
        for(int i=0; i<n; i++){
            if(pattern[i] == 'I'){
                int qs = q.size();
                for(int j=0; j<qs; j++){
                    map<char, int> m;
                    string tmp = q.front();
                    int tmpi = tmp[tmp.size()-1]-'0';
                    for(char c:tmp){
                        m[c] = 1;
                    }
                    q.pop();
                    for(int k=tmpi+1; k<10; k++){
                        if(m[k+'0'] != 1){
                            string tmp2 = tmp;
                            tmp2 += (k+'0');
                            q.push(tmp2);
                        }
                    }
                }
            }
            else{
                int qs = q.size();
                for(int j=0; j<qs; j++){
                    map<char, int> m;
                    string tmp = q.front();
                    int tmpi = tmp[tmp.size()-1]-'0';
                    for(char c:tmp){
                        m[c] = 1;
                    }
                    q.pop();
                    for(int k=1; k<tmpi; k++){
                        if(m[k+'0'] != 1){
                            string tmp2 = tmp;
                            tmp2 += (k+'0');
                            q.push(tmp2);
                        }
                    }
                }
            }
        }
        return q.front();
    }
};
