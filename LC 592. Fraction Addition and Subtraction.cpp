class Solution {
public:
    string fractionAddition(string expression) {
        string ret;
        long total = 0;
        int denominator = 2520;
        if(expression[0] != '+'){
            expression = "+" + expression;
        }
        string no = "", de = "";
        int sign = 0, flag = 0;
        for(char i:expression){
            if(i == '+' || i == '-'){
                if(de.size() != 0){
                    int nome = stoi(no);
                    total += (stoi(de) * 2520 / nome * sign);
                    no = "";
                    de = "";
                }
                if(i == '+'){
                    sign = 1;
                }
                else{
                    sign = -1;
                }
                flag = 0;
            }
            else if(i == '/'){
                flag = 1;
            }
            else if(flag == 1){
                no += i;
            }
            else{
                de += i;
            }
        }
        int nome = stoi(no);
        total += (stoi(de) * 2520 / nome * sign);
        if(total < 0){
            ret += '-';
            total = -total;
        }
        vector<int> v{2,2,2,3,3,5,7};
        int nomenator = 2520;
        for(int i:v){
            if(total % i == 0){
                total /= i;
                nomenator /= i;
            }
        }
        if(total == 0){
            return "0/1";x
        }
        ret += to_string(total);
        ret += '/';
        ret += to_string(nomenator);
        return ret;
    }
};
