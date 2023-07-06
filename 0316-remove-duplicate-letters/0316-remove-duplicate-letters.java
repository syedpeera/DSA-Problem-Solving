class Solution {
    public String removeDuplicateLetters(String s) {
        int[] count = new int[26];
        boolean[] visited = new boolean[26];
        Stack<Character> stack = new Stack<>();
        int n = s.length();

        for (char ch : s.toCharArray()) {
            count[ch - 'a']++;
        }

        for (char ch : s.toCharArray()) {
            count[ch - 'a']--;

            if (visited[ch - 'a']) {
                continue;
            }

            while (!stack.isEmpty() && stack.peek() > ch && count[stack.peek() - 'a'] > 0) {
                visited[stack.peek() - 'a'] = false;
                stack.pop();
            }

            stack.push(ch);
            visited[ch - 'a'] = true;
        }

        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.insert(0, stack.peek());
            stack.pop();
        }

        return sb.toString();
    }
}
