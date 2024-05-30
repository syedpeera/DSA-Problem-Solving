class Solution {

    public int countTriplets(int[] arr) {
        int size = arr.length;
        int count = 0;
        int prefix = 0;

        Map<Integer, Integer> countMap = new HashMap<>();
        countMap.put(0, 1);
        Map<Integer, Integer> totalMap = new HashMap<>();

        for (int i = 0; i < size; ++i) {
            prefix ^= arr[i];
            
            count +=
            countMap.getOrDefault(prefix, 0) * i -
            totalMap.getOrDefault(prefix, 0);

            totalMap.put(prefix, totalMap.getOrDefault(prefix, 0) + i + 1);
            countMap.put(prefix, countMap.getOrDefault(prefix, 0) + 1);
        }

        return count;
    }
}