class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result; // using this as a stack
        
        for(int i=0; i<s.size(); i++){
            result.push_back(s[i]);
            if(result.size() >= part.size() && result.substr(result.size() - part.size()) == part){
                int n = part.size();
                while(n > 0){
                    result.pop_back();
                    n = n - 1;
                }
            }
        }
        return result;
    }
};