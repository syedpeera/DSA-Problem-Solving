class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int W = words.size();
        maxScore = 0;
        freq = vector<int>(26, 0);
        vector<int> subsetLetters = vector<int>(26, 0);
        
        for (char c : letters) {
            freq[c - 'a']++;
        }
        check(W - 1, words, score, subsetLetters, 0);
        return maxScore;
    }

private:
    int maxScore;
    vector<int> freq;

    bool isValidWord(vector<int>& subsetLetters) {
        for (int c = 0; c < 26; c++) {
            if (freq[c] < subsetLetters[c]) {
                return false;
            }
        }
        return true;
    }

    void check(int w, vector<string>& words, vector<int>& score, vector<int>& subsetLetters, int totalScore) {
        if (w == -1) {
            maxScore = max(maxScore, totalScore);
            return;
        }
        
        check(w - 1, words, score, subsetLetters, totalScore);
        
        int L = words[w].length();
        for (int i = 0; i < L; i++) {
            int c = words[w][i] - 'a';
            subsetLetters[c]++;
            totalScore += score[c];
        }

        if (isValidWord(subsetLetters)) {
            
            check(w - 1, words, score, subsetLetters, totalScore);
        }
        
        for (int i = 0; i < L; i++) {
            int c = words[w][i] - 'a';
            subsetLetters[c]--;
            totalScore -= score[c];
        }
    }
};