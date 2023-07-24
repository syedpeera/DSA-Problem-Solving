class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        int currentNum = 0;
        string currentStr;
        
        for(char ch: s){
            if(isdigit(ch)){
                currentNum = currentNum * 10 + (ch - '0');
            }
            else if(ch == '['){
                numStack.push(currentNum);
                strStack.push(currentStr);
                
                currentNum = 0;
                currentStr.clear();
            }
            else if(ch == ']'){
                int num = numStack.top();
                numStack.pop();
                string decodedStr = strStack.top();
                strStack.pop();
                
                while(num > 0){
                    decodedStr = decodedStr + currentStr;
                    num--;
                }
                currentStr = decodedStr;
            }
            else{
                currentStr = currentStr + ch;
            }
        }
        return currentStr;
    }
};