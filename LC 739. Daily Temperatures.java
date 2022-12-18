class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] ret = new int[n];
        Stack<Integer> s1 = new Stack<>(), s2 = new Stack<>();
        for(int i=0; i<n; i++){
            ret[i] = 0;
        }
        for(int i=0; i<n; i++){
            if(s1.empty() || s1.peek() >= temperatures[i]){
                s1.add(temperatures[i]);
                s2.add(i);
            }
            else{
                while(!s1.empty() && s1.peek() < temperatures[i]){
                    s1.pop();
                    int tmp = s2.pop();
                    ret[tmp] = i-tmp;
                }
                s1.add(temperatures[i]);
                s2.add(i);
            }
        }
        return ret;
    }
}
