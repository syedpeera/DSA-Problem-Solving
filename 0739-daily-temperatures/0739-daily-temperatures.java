class Solution {
    public void reverse(int[] output, int left, int right){
        while(left < right){
            int temp = output[left];
            output[left] = output[right];
            output[right] = temp;
            
            left++;
            right--;
        }
    }
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> bucket = new Stack<>();
        int n = temperatures.length;
        int output[] = new int[n];
        int j=0;
        
        for(int i=n-1; i>=0; i--){
            if(bucket.isEmpty()){
                output[j++] = 0;
                bucket.add(i);
            }
            else{
                while(!bucket.isEmpty() && temperatures[bucket.peek()] <= temperatures[i]){
                    bucket.pop();
                }
                if(bucket.isEmpty()){
                    output[j++] = 0;
                    bucket.add(i);
                }
                else{
                    output[j++] = bucket.peek() - i;
                    bucket.add(i);
                }
            }
        }
        
        reverse(output, 0, n-1);
        
        return output;
    }
}