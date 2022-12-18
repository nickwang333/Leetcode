class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> s = new Stack<>();
        for(int i=0; i<tokens.length; i++){
            if(tokens[i].equals("+")){
                s.add(s.pop() + s.pop());
            } else if(tokens[i].equals("-")){
                int tmp1 = s.pop(), tmp2 = s.pop();
                s.add(tmp2-tmp1);
            } else if(tokens[i].equals("*")){
                s.add(s.pop() * s.pop());
            } else if(tokens[i].equals("/")){
                int tmp1 = s.pop(), tmp2 = s.pop();
                s.add(tmp2/tmp1);
            }
            else{
                s.add(Integer.parseInt(tokens[i]));
            }
        }
        return s.peek();
    }
}
