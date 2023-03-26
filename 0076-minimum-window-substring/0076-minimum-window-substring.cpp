class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int k=t.size();
        unordered_map<char, int> m;
        for(int i=0;i<k;i++){
            m[t[i]]++;
        }
        int i=0;
        int j=0;
        int count=m.size();
        int minLen=INT_MAX;
        int start=0;
        int end=0;
        while(j<n){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0){
                    count--;
                }
            }
            if(count>0){
                j++;
            }
            else if(count==0){
                if(minLen>j-i+1){
                    minLen=j-i+1;
                    start=i;
                    end=j;
                }
                while(count==0){
                    if(m.find(s[i])==m.end()){
                        i++;
                        if(minLen>j-i+1){
                            minLen=j-i+1;
                            start=i;
                            end=j;
                        }
                    }
                    else{
                        m[s[i]]++;
                        if(m[s[i]]>0){
                            i++;
                            count++;
                        }
                        else{
                            i++;
                            if(minLen>j-i+1){
                                minLen=j-i+1;
                                start=i;
                                end=j;
                            }
                        }
                    }
                }
                j++;
            }
        }
        string result="";
        if(minLen!=INT_MAX){
            for(int index=start;index<=end;index++){
                result=result+s[index];    
            }
        }
        return result;
    }
};