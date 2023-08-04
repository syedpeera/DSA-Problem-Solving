class Solution {
    public int minAddToMakeValid(String s) {
        Stack<Character> bucket = new Stack<>();
        int n = s.length();
        for(int i=0; i<n; i++){
            char ch = s.charAt(i);
            
            if(ch == '('){
                bucket.push(ch);
            }
            else if(!bucket.isEmpty() && bucket.peek() == '(' && ch == ')'){
                bucket.pop();
            }
            else{
                bucket.push(ch);
            }
        }
        return bucket.size();
    }
}