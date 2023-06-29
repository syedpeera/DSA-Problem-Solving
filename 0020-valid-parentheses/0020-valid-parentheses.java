class Solution {
    public boolean isValid(String s) {
        Stack<Character> bucket = new Stack<>();
        for(int i=0;i<s.length();i++){
            if(bucket.isEmpty()){
                bucket.add(s.charAt(i));
            }
            else if((bucket.peek()=='(' && s.charAt(i)==')') || (bucket.peek()=='{' && s.charAt(i)=='}') || (bucket.peek()=='[' && s.charAt(i)==']')){
                bucket.pop();
            }
            else{
                bucket.add(s.charAt(i));
            }
        }
        return bucket.isEmpty();
    }
}