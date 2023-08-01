class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //store index of element in stack
        stack<int> bucket;
        vector<int> result;
        int n = temperatures.size();
        for(int i=n-1; i>=0; i--){
            if(bucket.empty()){
                result.push_back(0);
                bucket.push(i);
            }
            else{
                while(!bucket.empty() && temperatures[bucket.top()] <= temperatures[i]){
                    bucket.pop();
                }
                if(bucket.empty()){
                    result.push_back(0);
                    bucket.push(i);
                }
                else{
                    result.push_back(bucket.top() - i);
                    bucket.push(i);
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};