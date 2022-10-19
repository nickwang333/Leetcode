class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ret;
        stack<int> s;
        for(int i=0; i<n; i++){
            if(asteroids[i] < 0){
                if(s.empty()){
                    ret.push_back(asteroids[i]);
                }
                else{
                    int destroyed = 0;
                    while(!s.empty()){
                        int tmp = s.top();
                        s.pop();
                        if(tmp > abs(asteroids[i])){
                            destroyed = 1;
                            s.push(tmp);
                            break;
                        }
                        else if(tmp == abs(asteroids[i])){
                            destroyed = 1;
                            break;
                        }
                    }
                    if(destroyed == 0){
                        ret.push_back(asteroids[i]);
                    }
                }
            }
            else{
                s.push(asteroids[i]);
            }
        }
        stack<int> s2;
        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }
        while(!s2.empty()){
            ret.push_back(s2.top());
            s2.pop();
        }
        return ret;
    }
};
