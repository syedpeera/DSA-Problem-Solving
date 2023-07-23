class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq;
        for (int i=0; i<t.size(); i++) {
            tFreq[t[i]]++;
        }
        
        int left = 0;
        int minLen = INT_MAX;
        int required = tFreq.size();
        int minStart = 0;
        string result;
        
        for(int right=0; right<s.size(); right++) {
            if (tFreq.find(s[right]) != tFreq.end()) {
                tFreq[s[right]]--;
                if (tFreq[s[right]] == 0) {
                    required--;
                }
            }
            
            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                if (tFreq.find(s[left]) != tFreq.end()) {
                    tFreq[s[left]]++;
                    if (tFreq[s[left]] > 0) {
                        required++;
                    }
                }
                left++;
            }
        }
        
        return minLen == INT_MAX? "" : s.substr(minStart, minLen);
    }
};
