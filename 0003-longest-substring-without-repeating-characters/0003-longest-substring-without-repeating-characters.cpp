class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_set<char> uniqueCharacters;
        int left = 0;
        int right = 0;
        int n = s.size();
        while(right < n){
            if(uniqueCharacters.find(s[right]) == uniqueCharacters.end()){
                uniqueCharacters.insert(s[right]);
                maxLen = max(maxLen, right-left+1);
                right++;
            }
            else{
                uniqueCharacters.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};