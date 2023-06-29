class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int maxElement = 0;
        int chunkCount = 0;
        for(int i=0;i<n;i++){
            maxElement = Math.max(maxElement, arr[i]);
            if(maxElement == i){
                chunkCount++;
            }
        }
        return chunkCount;
    }
}