class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ret(n);
        int left = 0, total = 0, right = 0;
        for(int i=0; i<n; i++){
            total += left;
            if(boxes[i] == '1'){
                left++;
            }
        }
        ret[n-1] = total;
        for(int i=n-1; i>0; i--){
            if(boxes[i] == '1'){
                left--;
                right++;
            }
            total -= left;
            total += right;
            ret[i-1] = total;
        }

        return ret;
    }
};
