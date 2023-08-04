class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> bucket;
        int n = s.size();
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch == '('){
                bucket.push(ch);
            }
            else if(!bucket.empty() && bucket.top() == '(' && ch == ')'){
                bucket.pop();
            }
            else{
                bucket.push(ch);
            }
        }
        return bucket.size();
    }
};