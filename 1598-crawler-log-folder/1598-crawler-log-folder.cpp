class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> folderStack;

        for (const string& currentOperation : logs) {
            if (currentOperation == "../") {
                if (!folderStack.empty()) {
                    folderStack.pop();
                }
            } else if (currentOperation != "./") {
                folderStack.push(currentOperation);
            }
        }

        return folderStack.size();
    }
};