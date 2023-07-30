class Solution {
    public int distributeCandies(int[] candyType) {
        int n = candyType.length;
        int maxTypes = n/2;
        Set<Integer> uniqueCandies = new HashSet<>();
        for(int candy: candyType){
            uniqueCandies.add(candy);
        }
        return Math.min(maxTypes, uniqueCandies.size());
    }
}