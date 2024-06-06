class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }
        map<int, int> m, m2;
        for(int i:hand){
            m[i]++;
        }
        m2 = m;
        for(auto i:m2){
            int tmp = i.first;
            if(m[tmp] < 0){
                return false;
            }
            if(m[tmp] == 0){
                continue;
            }
            for(int j=1; j<groupSize; j++){
                m[tmp+j] -= m[tmp];
                if(m[tmp+j] < 0){
                    return false;
                }
            }
            m[tmp] = 0;
        }
        return true;
    }
};
