class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        //index
        stack<int> bucket;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                bucket.push(i);
            }
            else if(s[i] == ')'){
                if(bucket.empty()){
                    s[i] = '*'; //invalid
                }
                else{
                    bucket.pop();
                }
            }
        }
        
        while(!bucket.empty()){
            s[bucket.top()] = '*'; //invalid
            bucket.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};