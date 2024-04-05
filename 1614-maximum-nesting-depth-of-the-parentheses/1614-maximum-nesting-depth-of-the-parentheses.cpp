class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int currentDepth = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                currentDepth++;
                maxDepth = max(maxDepth, currentDepth);
            } else if (ch == ')') {
                currentDepth--;
            }
        }
        
        return maxDepth;
    }
};