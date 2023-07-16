class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> map;
        int count = 0;
        for(int duration: time){
            int reminder = (duration % 60);
            int compliment = (60 - reminder) % 60;
            count = count + map[compliment];
            map[reminder]++;
        }
        return count;
    }
};