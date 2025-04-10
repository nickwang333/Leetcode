class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0){
            return "0";
        }
        string dec = "", rep = "";
        long long tmp1, tmp2;
        int flag = 1;
        if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)){
            flag = -1;
        }
        tmp1 = abs((long)numerator);
        tmp2 = abs((long)denominator);
        long integer_part = tmp1 / tmp2;
        tmp1 %= tmp2;
        if(tmp1 == 0){
            if(flag == -1){
                return "-" + to_string(integer_part);
            }
            return to_string(integer_part);
        }
        unordered_map<int, int> m;
        while(1){
            if(m.find(tmp1) != m.end()){
                dec.insert(m[tmp1], "(");
                dec += ")";
                break;
            }
            m[tmp1] = dec.size();
            tmp1 *= 10;
            int tmp = tmp1/tmp2;
            tmp1 %= tmp2;
            if(tmp1 == 0){
                if(flag == -1){
                    return "-" + to_string(integer_part) + "." + dec + to_string(tmp);
                }
                return to_string(integer_part) + "." + dec + to_string(tmp);
            }
            
            dec += to_string(tmp);
        }
        if(flag == -1){
            return "-" + to_string(integer_part) + "." + dec; 
        }
        return to_string(integer_part) + "." + dec; 
    }
};
