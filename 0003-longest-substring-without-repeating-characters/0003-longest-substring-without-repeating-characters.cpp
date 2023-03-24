class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        int maxLen=0;
        unordered_map<char, int> m;
        while(j<n){
            m[s[j]]++;
            if(m.size()==j-i+1){
                maxLen=max(maxLen,j-i+1);
                j++;
            }
            else if(m.size()<j-i+1){
                while(m.size()<j-i+1){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
                if(m.size()==j-i+1){
                    maxLen=max(maxLen, j-i+1);
                    j++;
                }
            }
        }
        return maxLen;
    }
};