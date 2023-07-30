class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> uniqueTypes;
        int n = candyType.size();
        int maxTypes = n/2;
        for(int candy: candyType){
            uniqueTypes.insert(candy);
        }
        return min(maxTypes, (int)uniqueTypes.size());
    }
};