class Solution {
public:
    int maximumSwap(int num) {
        string tmp = to_string(num);
        string tmp2 = to_string(num);
        int n = tmp.size();
        sort(tmp.rbegin(), tmp.rend());
        for(int i=0; i<n; i++){
            if(tmp[i] != tmp2[i]){
                int pos = i;
                for(int j=n-1; j>=0; j--){
                    if(tmp2[j] == tmp[i]){
                        swap(tmp2[j], tmp2[i]);
                        return stoi(tmp2);
                    }
                }
            }
        }
        return num;
    }
};
