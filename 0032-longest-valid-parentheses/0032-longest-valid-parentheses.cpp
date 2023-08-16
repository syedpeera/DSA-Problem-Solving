class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxLength = 0;
        stack<int> bucket;
        bucket.push(-1);
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                bucket.push(i);
            }
            else{
                bucket.pop();
                if(bucket.empty()){
                    bucket.push(i);
                }
                else{
                    maxLength = max(maxLength, i-bucket.top());
                }
            }
        }
        return maxLength;
    }
};