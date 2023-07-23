class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetChars;
    for (char c : t) {
        targetChars[c]++;
    }

    int left = 0;
    int minLen = INT_MAX;
    int minStart = 0;
    int requiredChars = targetChars.size();

    for (int right = 0; right < s.length(); right++) {
        char rightChar = s[right];
        if (targetChars.count(rightChar)) {
            targetChars[rightChar]--;
            if (targetChars[rightChar] == 0) {
                requiredChars--;
            }
        }

        while (requiredChars == 0) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            char leftChar = s[left];
            if (targetChars.count(leftChar)) {
                targetChars[leftChar]++;
                if (targetChars[leftChar] > 0) {
                    requiredChars++;
                }
            }

            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
