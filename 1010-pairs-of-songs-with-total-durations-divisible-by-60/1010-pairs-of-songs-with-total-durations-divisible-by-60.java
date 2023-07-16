class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;
        for(int duration : time){
            int reminder = (duration % 60);
            int compliment = (60 - reminder) % 60;
            count = count + map.getOrDefault(compliment, 0);
            map.put(reminder, map.getOrDefault(reminder, 0)+1);
        }
        return count;
    }
}