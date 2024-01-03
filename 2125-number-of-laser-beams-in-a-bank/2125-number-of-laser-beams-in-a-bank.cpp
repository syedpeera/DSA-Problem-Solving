class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int previousDeviceCount = 0;
        int result = 0;
        for(int i=0; i<n; i++){
            int currentDeviceCount = 0;
            for(char &ch: bank[i]){
                if(ch == '1'){
                    currentDeviceCount++;
                }
            }
            result = result + (previousDeviceCount * currentDeviceCount);
            if(currentDeviceCount != 0){
                previousDeviceCount = currentDeviceCount;
            }
        }
        return result;
    }
};