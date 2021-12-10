class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        long long ret = 0, tmp = 0;
        vector<long long> even, odd;
        for(int i:nums){
            if(i%2==0){
                even.push_back(i);
            }
            else{
                odd.push_back(i);
            }
        }
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());
        long long odd_num;
        if(even.size()>=k){
            odd_num = 0;
        }
        else{
            if((k-even.size())%2==0){
                odd_num = k-even.size();
            }
            else{
                odd_num = k-even.size()+1;
            }
        }
        if(odd_num > odd.size() || odd_num>k){
            return -1;
        }
        for(int i=0; i<odd_num; i++){
            tmp += odd[i];
        }
        for(int i=0; i<k-odd_num; i++){//computing prefix sum
            tmp += even[i];
        }
        ret = tmp;
        int fp = odd_num, sp = k-odd_num;
        while(fp+2<=odd.size() && sp-2>=0){
            tmp += odd[fp];
            fp++;
            tmp += odd[fp];
            fp++;
            sp--;
            tmp -= even[sp];
            sp--;
            tmp -= even[sp];
            ret = max(ret,tmp);
        }
        return ret;
    }
};
