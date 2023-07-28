class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        
        string commonPrefix = strs[0];
        for(int i=1; i<strs.size(); i++){
            int j = 0;
            while(j < commonPrefix.size() && j < strs[i].size() && commonPrefix[j] == strs[i][j]){
                j++;
            }
            commonPrefix = commonPrefix.substr(0, j);
            if(commonPrefix.length() == 0){
                break;
            }
        }
        return commonPrefix;
    }
};