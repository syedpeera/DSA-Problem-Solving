class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int maxCount = 0;
        int n = s.size();
        int i = 0;
        unordered_map<char, int> map;
        for(int j = 0; j < n; j++){
            map[s[j]]++;
            
            maxCount = max(maxCount, map[s[j]]);
            
            if(((j-i+1)-maxCount) > k){
                map[s[i]]--;
                i++;
            }
            
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};