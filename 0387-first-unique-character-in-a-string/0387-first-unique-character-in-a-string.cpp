class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> sFreq(26, 0);
        for(int i=0; i<n; i++){
            sFreq[s[i] - 'a']++;
        }
        for(int i=0; i<n; i++){
            if(sFreq[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};