class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        stack<char> bucket;
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            count[s[i]-'a']--;
            if(visited[s[i]-'a']){
                continue;
            }
            while(!bucket.empty() && bucket.top()>s[i] && count[bucket.top()-'a']>0){
                visited[bucket.top()-'a'] = false;
                bucket.pop();
            }
            bucket.push(s[i]);
            visited[s[i]-'a']=true;
        }
        string result = "";
        while(!bucket.empty()){
            result.insert(result.begin(), bucket.top());
            bucket.pop();
        }
        return result;
    }
};