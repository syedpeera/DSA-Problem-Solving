class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int maxLength = 0;
        Stack<Integer> bucket = new Stack();
        bucket.push(-1);
        for(int i=0; i<n; i++){
            if(s.charAt(i) == '('){
                bucket.push(i);
            }
            else{
                bucket.pop();
                if(bucket.isEmpty()){
                    bucket.push(i);
                }
                else{
                    maxLength = Math.max(maxLength, i-bucket.peek());
                }
            }
        }
        return maxLength;
    }
}