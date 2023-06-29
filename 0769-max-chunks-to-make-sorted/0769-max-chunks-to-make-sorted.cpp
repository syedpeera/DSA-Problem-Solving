class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxElement = 0;
        int chunkCount = 0;
        for(int i=0;i<n;i++){
            maxElement = max(maxElement, arr[i]);
            if(maxElement==i){
                chunkCount++;
            }
        }
        return chunkCount;
    }
};