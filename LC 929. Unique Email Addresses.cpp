class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, int> m;
        for(string i: emails){
            string tmp = "";
            int flag = 0, flag2 = 0;
            for(char j:i){
                if(j == '@'){
                    flag = 1;
                    tmp += j;
                }
                else if(flag == 1){
                    tmp += j;
                }
                else if(j == '.'){
                    continue;
                }
                else if(j == '+'){
                    flag2 = 1;
                }
                else if(flag2 == 0){
                    tmp += j;
                }
            }
            
            m[tmp]++;
        }
        return m.size();
    }
};
