class Solution {
    public String smallestSubsequence(String s) {
        int count[] = new int[26];
        boolean visited[] = new boolean[26];
        Stack<Character> stack = new Stack<>();
        int n = s.length();
        for(int i=0;i<n;i++){
            count[s.charAt(i)-'a']++;
        }
        for(int i=0;i<n;i++){
            count[s.charAt(i)-'a']--;
            if(visited[s.charAt(i)-'a']){
                continue;
            }
            while(!stack.isEmpty() && stack.peek()>s.charAt(i) && count[stack.peek()-'a']>0){
                visited[stack.peek()-'a'] = false;
                stack.pop();
            }
            stack.push(s.charAt(i));
            visited[s.charAt(i)-'a'] = true;
        }
        StringBuilder sb = new StringBuilder();
        while(!stack.isEmpty()){
            sb.insert(0, stack.peek());
            stack.pop();
        }
        return sb.toString();
    }
}