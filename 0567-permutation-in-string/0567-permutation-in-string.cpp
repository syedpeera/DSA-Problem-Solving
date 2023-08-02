class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        if(n1 > n2){
            return false;
        }
        
        int k = n1;
        vector<int> s1Freq(26, 0);
        vector<int> s2Freq(26, 0);
        
        for(int i=0; i<k; i++){
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }
        
        if(s1Freq == s2Freq){
            return true;
        }
        
        int left = 0;
        for(int right = k; right<n2; right++){
            s2Freq[s2[left] - 'a']--;
            left++;
            s2Freq[s2[right] - 'a']++;
            
            if(s1Freq == s2Freq){
                return true;
            }
        }
        return false;
    }
};