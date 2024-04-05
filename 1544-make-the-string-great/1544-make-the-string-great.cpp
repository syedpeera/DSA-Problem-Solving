#include <string>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string result;
        
        for (char ch : s) {
            // If the result is not empty and the current character cancels the last one
            if (!result.empty() && abs(result.back() - ch) == 32) {
                result.pop_back(); // Remove the last character from the result
            } else {
                result.push_back(ch); // Otherwise, add the current character to the result
            }
        }
        
        return result;
    }
};
