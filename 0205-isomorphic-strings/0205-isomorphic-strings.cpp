class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        int n = s.size();
        for(int i=0; i<n; i++){
            char ch1 = s[i];
            char ch2 = t[i];
            if((map1.find(ch1) != map1.end() && map1[ch1] != ch2) || (map2.find(ch2) != map2.end() && map2[ch2] != ch1)){
                return false;
            }
            map1[ch1] = ch2;
            map2[ch2] = ch1;
        }
        return true;
    }
};