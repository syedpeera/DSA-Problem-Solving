class Solution {
public:
    int calculate(string s) {
        stack<int> numStack;
        stack<int> opStack;
        int result = 0;
        int sign = 1;
        int num = 0;
        for(char ch: s){
            if(isdigit(ch)){
                num = (num * 10) + (ch - '0');
            }
            else if(ch == '+'){
                result = result + sign * num;
                sign = 1;
                num = 0;
            }
            else if(ch == '-'){
                result = result + sign * num;
                sign = -1;
                num = 0;
            }
            else if(ch == '('){
                opStack.push(sign);
                numStack.push(result);
                sign = 1;
                result = 0;
            }
            else if(ch == ')'){
                result = result + sign * num;
                num = 0;
                result = result * opStack.top();
                opStack.pop();
                result = result + numStack.top();
                numStack.pop();
            }
        }
        result = result + sign * num;
        return result;
    }
};