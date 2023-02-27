class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        int length = s.size();
        for(int i=0;i<length;i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')){
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        if(st.empty())
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};