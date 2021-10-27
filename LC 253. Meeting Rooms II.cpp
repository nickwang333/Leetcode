class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ret = 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int> pq;
        for(auto i:intervals){
            if(pq.empty()){
                ret++;
                pq.push(-i[1]);
            }
            else{
                if(i[0]>=-pq.top()){
                    pq.pop();
                    pq.push(-i[1]);
                }
                else{
                    ret++;
                    pq.push(-i[1]);
                }
            }
        }
        return ret;
    }
};
