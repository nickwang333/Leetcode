class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> m, m2;
        int prev = 0, n = people.size();
        vector<int> ret(n), v;
        for(auto i:flowers){
            m[i[0]]++;
            m[i[1]+1]--;
        }
        for(auto it:m){
            prev += it.second;
            m2[it.first] = prev;
            v.push_back(it.first);
        }
        
        for(int i=0; i<n; i++){
            int begin = 0, end = v.size()-1, mid;
            if(people[i] < v[0] || people[i] > v[end]){
                ret[i] = 0;
                continue;
            }
            while(begin < end){
                mid = (begin + end)/2;
                if(v[mid] < people[i]){
                    begin = mid+1;
                }
                else{
                    end = mid;
                }
            }
            if(v[begin] > people[i]){
                begin--;
            }
            ret[i] = m2[v[begin]];
        }
        return ret;
    }
};
