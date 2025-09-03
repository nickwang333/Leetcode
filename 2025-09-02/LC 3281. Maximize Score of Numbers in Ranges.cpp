class Solution {
public:
    bool valid(vector<int>& start, int d, int val){
        long long n = start.size(), prev = start[0];
        for(int i=1; i<n; i++){
            long long tmp1 = start[i];
            if(tmp1 + d < long (prev) + long(val)){
                return false;
            }
            prev = max(prev+val, tmp1);
        }
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        long long n = start.size(), low = 0, high = start.back() - start.front() + d;

        long long mid, ret;
        while(high >= low){
            mid = (high-low)/2 + low;
            if(valid(start, d, mid)){
                ret = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ret;
    }
};
