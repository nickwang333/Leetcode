class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ret;
        int counter = 1;
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
        while(counter < n){
            counter++;
            int qs = q.size();
            for(int i=0; i<qs; i++){
                string tmp = q.front();
                q.pop();
                int last_digit = tmp[tmp.size()-1]-'0';
                if(last_digit+k <= 9){
                    string tmp2 = tmp;
                    tmp2 += to_string(last_digit+k);
                    q.push(tmp2);
                }
                if(last_digit-k >= 0 && k!=0){
                    string tmp2 = tmp;
                    tmp2 += to_string(last_digit-k);
                    q.push(tmp2);
                }
            }
        }
        while(!q.empty()){
            ret.push_back(stoi(q.front()));
            q.pop();
        }
        return ret;
    }
};
