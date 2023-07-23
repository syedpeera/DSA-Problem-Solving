class Solution {
public:
    int expandAroundCenter(string &s, int left, int right){
        int count = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<n; i++){
            //odd length
            count = count + expandAroundCenter(s, i, i);
            
            //even length
            count = count + expandAroundCenter(s, i, i+1);
        }
        return count;
    }
};