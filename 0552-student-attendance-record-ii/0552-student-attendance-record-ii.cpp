class Solution {
public:
    int checkRecord(int n) {
        int MOD = 1000000007;
        
        vector<vector<int>> dpCurrState = vector<vector<int>>(2, vector<int>(3, 0));
        
        vector<vector<int>> dpNextState = vector<vector<int>>(2, vector<int>(3, 0));

        
        dpCurrState[0][0] = 1;

        
        
        for (int len = 0; len < n; ++len) {
            for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
                for (int consecutiveLates = 0; consecutiveLates <= 2; ++consecutiveLates) {
        
                    dpNextState[totalAbsences][0] = (
                        dpNextState[totalAbsences][0] + 
                        dpCurrState[totalAbsences][consecutiveLates]
                    ) % MOD;
        
                    if (totalAbsences < 1) {
                        dpNextState[totalAbsences + 1][0] = (
                            dpNextState[totalAbsences + 1][0] + 
                            dpCurrState[totalAbsences][consecutiveLates]
                        ) % MOD;
                    }
        
                    if (consecutiveLates < 2) {
                        dpNextState[totalAbsences][consecutiveLates + 1] = (
                            dpNextState[totalAbsences][consecutiveLates + 1] + 
                            dpCurrState[totalAbsences][consecutiveLates]
                        ) % MOD;
                    }
                }
            }
            
        
            dpCurrState = dpNextState;
            
            dpNextState = vector<vector<int>>(2, vector<int>(3, 0));
        }

    
        int count = 0;
        for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
            for (int consecutiveLates = 0; consecutiveLates <= 2; ++consecutiveLates) {
                count = (count + dpCurrState[totalAbsences][consecutiveLates]) % MOD;
            }
        }
        return count;
    }
};