void add_string(queue<string>& q, char c, string& s){
    string tmp;
    if(c=='2'){
        tmp = s; tmp += 'a'; q.push(tmp);
        tmp = s; tmp += 'b'; q.push(tmp);
        tmp = s; tmp += 'c'; q.push(tmp);
    }
    else if(c=='3'){
        tmp = s; tmp += 'd'; q.push(tmp);
        tmp = s; tmp += 'e'; q.push(tmp);
        tmp = s; tmp += 'f'; q.push(tmp);
    }
    else if(c=='4'){
        tmp = s; tmp += 'g'; q.push(tmp);
        tmp = s; tmp += 'h'; q.push(tmp);
        tmp = s; tmp += 'i'; q.push(tmp);
    }
    else if(c=='5'){
        tmp = s; tmp += 'j'; q.push(tmp);
        tmp = s; tmp += 'k'; q.push(tmp);
        tmp = s; tmp += 'l'; q.push(tmp);
    }
    else if(c=='6'){
        tmp = s; tmp += 'm'; q.push(tmp);
        tmp = s; tmp += 'n'; q.push(tmp);
        tmp = s; tmp += 'o'; q.push(tmp);
    }
    else if(c=='7'){
        tmp = s; tmp += 'p'; q.push(tmp);
        tmp = s; tmp += 'q'; q.push(tmp);
        tmp = s; tmp += 'r'; q.push(tmp);
        tmp = s; tmp += 's'; q.push(tmp);
    }
    else if(c=='8'){
        tmp = s; tmp += 't'; q.push(tmp);
        tmp = s; tmp += 'u'; q.push(tmp);
        tmp = s; tmp += 'v'; q.push(tmp);
    }
    else if(c=='9'){
        tmp = s; tmp += 'w'; q.push(tmp);
        tmp = s; tmp += 'x'; q.push(tmp);
        tmp = s; tmp += 'y'; q.push(tmp);
        tmp = s; tmp += 'z'; q.push(tmp);
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<string> q;
        vector<string> ret;
        int n = digits.size();
        if(n==0){return ret;}
        for(int i=0; i<n; i++){
            if(i==0){
                string tmp;
                add_string(q, digits[i], tmp);
            }
            else{
                int qs = q.size();
                for(int j=0; j<qs; j++){
                    string tmp = q.front();
                    q.pop();
                    add_string(q, digits[i], tmp);
                }
            }
        }
        while(!q.empty()){
            string tmp = q.front();
            ret.push_back(tmp);
            q.pop();
        }
        return ret;
    }
};
