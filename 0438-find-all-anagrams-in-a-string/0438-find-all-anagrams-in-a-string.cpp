class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(s.empty() || p.empty() || s.size() < p.size()){
            return result;
        }
        
        vector<int> sCount(26, 0);
        vector<int> pCount(26, 0);
        
        for(char ch: p){
            pCount[ch - 'a']++;
        }
        
        int k = p.size();
        for(int i=0; i<k; i++){
            sCount[s[i] - 'a']++;
        }
        
        if(sCount == pCount){
            result.push_back(0);
        }
        
        int left = 0;
        for(int right=k; right<s.size(); right++){
            sCount[s[left] - 'a']--;
            left++;
            
            sCount[s[right] - 'a']++;
            
            if(sCount == pCount){
                result.push_back(left);
            }
        }
        return result;
    }
};