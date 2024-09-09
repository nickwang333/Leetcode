class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int p1 = 0, p2 = 0, m = slots1.size(), n = slots2.size();
        while(p1 <= m-1 || p2 <= n-1){
            int d1 = slots1[p1][1] - slots1[p1][0];
            int d2 = slots2[p2][1] - slots2[p2][0];
            if(d1 >= duration && (slots1[p1][0] + duration) <= slots2[p2][1] && ((slots1[p1][0]) >= slots2[p2][0])){
                return vector<int>{slots1[p1][0], slots1[p1][0] + duration};
            }
            if(d2 >= duration && (slots2[p2][0] + duration) <= slots1[p1][1] && (slots2[p2][0]) >= slots1[p1][0]){
                return vector<int>{slots2[p2][0], slots2[p2][0] + duration};
            }
            if(p2 == n-1 || ((slots2[p2][1] > slots1[p1][1] && p1 != m-1))){
                if(p1 == m-1){
                    return vector<int>{};
                }
                p1++;
            }
            else{
                p2++;
            }
        }
        return vector<int>{};
    }
};
