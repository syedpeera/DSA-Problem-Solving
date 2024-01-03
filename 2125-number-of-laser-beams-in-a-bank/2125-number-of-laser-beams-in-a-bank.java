class Solution {
    public int numberOfBeams(String[] bank) {
        int n = bank.length;
        int previousDeviceCount = 0;
        int result = 0;
        for(int i=0; i<n; i++){
            int currentDeviceCount = 0;
            for(Character ch: bank[i].toCharArray()){
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
}