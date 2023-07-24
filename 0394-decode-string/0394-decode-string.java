class Solution {
    public String decodeString(String s) {
        Stack<Integer> numStack = new Stack<>();
        Stack<StringBuilder> strStack = new Stack<>();
        int currentNum = 0;
        StringBuilder currentStr = new StringBuilder();
        
        for(char ch: s.toCharArray()){
            if(Character.isDigit(ch)){
                currentNum = currentNum * 10 + (ch - '0');
            }
            else if(ch == '['){
                numStack.add(currentNum);
                strStack.add(currentStr);
                
                currentNum = 0;
                currentStr = new StringBuilder();
            }
            else if(ch == ']'){
                int num = numStack.peek();
                numStack.pop();
                StringBuilder decodedStr = strStack.peek();
                strStack.pop();
                
                while(num > 0){
                    decodedStr.append(currentStr);
                    num--;
                }
                currentStr = decodedStr;
            }
            else{
                currentStr.append(ch);
            }
        }
        return currentStr.toString();
    }
}