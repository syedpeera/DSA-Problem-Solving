class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1!=n2){
            return false;
        }
        unordered_map<char, int> map;
        for(int i=0;i<n1;i++){
            map[s[i]]++;
        }
        for(int i=0;i<n2;i++){
            if(map.find(t[i])==map.end()){
                return false;
            }
            map[t[i]]--;
            if(map[t[i]]==0){
                map.erase(t[i]);
            }
        }
        return map.empty();
    }
};