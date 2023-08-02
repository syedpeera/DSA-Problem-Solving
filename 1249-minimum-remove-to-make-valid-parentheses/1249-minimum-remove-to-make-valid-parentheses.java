class Solution {
    public String minRemoveToMakeValid(String s) {
        int n = s.length();
        //index
        Stack<Integer> bucket = new Stack<>();
        char charArr[] = s.toCharArray();
        
        for(int i=0; i<n; i++){
            if(charArr[i] == '('){
                bucket.add(i);
            }
            else if(charArr[i] == ')'){
                if(bucket.isEmpty()){
                    charArr[i] = '*'; //invalid
                }
                else{
                    bucket.pop();
                }
            }
        }
        while(!bucket.isEmpty()){
            charArr[bucket.peek()] = '*'; //invalid
            bucket.pop();
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<n; i++){
            if(charArr[i] != '*'){
                sb.append(charArr[i]);
            }
        }
        return sb.toString();
    }
}