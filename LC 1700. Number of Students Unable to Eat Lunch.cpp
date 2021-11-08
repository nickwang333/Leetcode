class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q1, q2;
        int one = 0, zero = 0, tmp1 = 0;
        for(int i=0; i<students.size(); i++){
            q1.push(students[i]);
            q2.push(sandwiches[i]);
            if(students[i]==1){
                one++;
            }
            else{
                zero++;
            }
            tmp1 += sandwiches[i];
        }
        if(tmp1 == one){
            return 0;
        }
        while(one != 0 && zero != 0){
            if(q1.front() == q2.front()){
                if(q1.front()==1){
                    one--;
                }
                else{
                    zero--;
                }
                q1.pop();
                q2.pop();
            }
            else{
                int tmp = q1.front();
                q1.pop();
                q1.push(tmp);
            }
        }
        int tmp = q1.size();
        for(int i=0; i<tmp; i++){
            if(q1.front() == q2.front()){
                if(q1.front()==1){
                    one--;
                }
                else{
                    zero--;
                }
                q1.pop();
                q2.pop();
            }
            else{
                int tmp = q1.front();
                q1.pop();
                q1.push(tmp);
            }
        }
        return zero + one;
    }
};
