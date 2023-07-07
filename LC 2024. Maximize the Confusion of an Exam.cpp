class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size(), ret = 0, t=0, f=0;
        vector<int> v(n, 1), v2(n, 1);
        unordered_map<int, int> t1, f1;
        for(int i=0; i<n; i++){
            if(i!=0){
                if(answerKey[i] == answerKey[i-1]){
                    v[i] = v[i-1]+1;
                }
            }
            if(answerKey[i] == 'T'){
                t++;
                t1[t] = i;
            }
            else{
                f++;
                f1[f] = i;
            }
        }
        v2[n-1] = v[n-1];
        for(int i=n-2; i>=0; i--){
            if(v[i] == v[i+1]-1){
                v2[i] = v2[i+1];
            }
            else{
                v2[i] = v[i];
            }
            ret = max(ret, v2[i]);
        }
        //analyze false
        for(auto i:t1){
            int tmp = 0;
            if(t1.find(i.first + k - 1) != t1.end()){
                int begin = i.second, end = t1[i.first+k-1];
                if(begin > 0 && answerKey[begin-1] == 'F'){
                    tmp += v2[begin-1];
                }
                if(end < n-1 && answerKey[end+1] == 'F'){
                    tmp += v2[end+1];
                }
                tmp += (end-begin+1);
            }
            else{
                int begin = i.second, end = n-1;
                if(begin > 0 && answerKey[begin-1] == 'F'){
                    tmp += v2[begin-1];
                }
                if(end < n-1 && answerKey[end+1] == 'F'){
                    tmp += v2[end+1];
                }
                tmp += (end-begin+1);
            }
            ret = max(ret, tmp);
        }

        for(auto i:f1){
            int tmp = 0;
            if(f1.find(i.first + k - 1) != f1.end()){
                int begin = i.second, end = f1[i.first+k-1];
                if(begin > 0 && answerKey[begin-1] == 'T'){
                    tmp += v2[begin-1];
                }
                if(end < n-1 && answerKey[end+1] == 'T'){
                    tmp += v2[end+1];
                }
                tmp += (end-begin+1);
            }
            else{
                int begin = i.second, end = n-1;
                if(begin > 0 && answerKey[begin-1] == 'T'){
                    tmp += v2[begin-1];
                }
                if(end < n-1 && answerKey[end+1] == 'T'){
                    tmp += v2[end+1];
                }
                tmp += (end-begin+1);
            }
            ret = max(ret, tmp);
        }
        return ret;
    }
};
