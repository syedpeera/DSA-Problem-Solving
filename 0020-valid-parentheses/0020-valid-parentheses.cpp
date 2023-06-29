class Solution {
public:
    bool isValid(string s) {
        stack<char> bucket;
        
        for(int i=0;i<s.size();i++)
        {
            if(bucket.empty())
            {
                bucket.push(s[i]);
            }
            else if( (bucket.top()=='(' && s[i]==')') || (bucket.top()=='[' && s[i]==']') || (bucket.top()=='{' && s[i]=='}'))
            {
                bucket.pop();
            }
            else
            {
                bucket.push(s[i]);
            }
        }
        return bucket.empty();
    }
};