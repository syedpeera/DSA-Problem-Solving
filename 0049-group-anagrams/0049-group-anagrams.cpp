class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroup;
        int n = strs.size();
        for(int i=0;i<n;i++){
            vector<int> charCount(26, 0);
            for(char c: strs[i]){
                charCount[c - 'a']++;
            }
            string key;
            for(int charVal: charCount){
                key = key + to_string(charVal)+"#";
            }
            anagramGroup[key].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto x: anagramGroup){
            result.push_back(x.second);
        }
        return result;
    }
};