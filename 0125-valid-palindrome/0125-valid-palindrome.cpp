class Solution {
public:
    bool isPalindrome(string s) 
    {
        string str="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                str += tolower(s[i]);
            }
            else if(s[i]>='a' && s[i]<='z')
            {
                str += s[i];
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                str += s[i];
            }
        }
        for(int i=0;i<str.size()/2;i++)
        {
            if(str[i]!=str[str.size()-1-i])
            {
                return false;
            }
        }
        return true;
    }
};