class Solution {
public:
    long long smallestNumber(long long num) {
        long long ret = 0;
        map<int,int> v;
        if(num>=0){
            while(num>0){
                v[num%10]++;
                num/=10;
            }
            for(auto it=v.begin(); it!=v.end(); it++){
                if(it->first == 0){
                    auto it2 = it;
                    it2++;
                    ret = it2->first;
                    it2->second--;
                }
                for(int i=0; i<it->second; i++){
                    ret *= 10;
                    ret += it->first;
                }
            }
        }
        else{
            long long tmp = -num;
            while(tmp>0){
                v[tmp%10]++;
                tmp/=10;
            }
            for(auto it=v.rbegin(); it!=v.rend(); it++){
                
                for(int i=0; i<it->second; i++){
                    ret *= 10;
                    ret += it->first;
                }
            }
            ret = -ret;
        }
        return ret;
    }
};
