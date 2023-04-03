class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int start = 0, end = people.size()-1, ret = 0;
        while(start <= end){
            if(start == end){
                ret++;
                break;
            }
            if(people[start] + people[end] <= limit){
                ret++;
                start++;
                end--;
            }
            else{
                ret++;
                end--;
            }
        }
        return ret;
    }
};
