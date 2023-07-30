class Solution {
    public int calculate(String s) {
        Stack<Integer> numStack = new Stack<>();
        Stack<Integer> opStack = new Stack<>();
        int result = 0;
        int num = 0;
        int sign = 1;
        
        for(char ch: s.toCharArray()){
            if(Character.isDigit(ch)){
                num = (num * 10) + (ch - '0');
            }
            else if(ch == '+'){
                result = result + sign * num;
                num = 0;
                sign = 1;
            }
            else if(ch == '-'){
                result = result + sign * num;
                num = 0;
                sign = -1;
            }
            else if(ch == '('){
                numStack.add(result);
                opStack.add(sign);
                result = 0;
                sign = 1;
            }
            else if(ch == ')'){
                result = result + sign * num;
                num = 0;
                result = result * opStack.peek();
                opStack.pop();
                result = result + numStack.peek();
                numStack.pop();
            }
        }
        
        result = result + sign * num;
        return result;
    }
}