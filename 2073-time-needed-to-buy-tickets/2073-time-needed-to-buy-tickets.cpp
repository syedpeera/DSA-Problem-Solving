class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int n = tickets.size();
        for(int i=0; i<n; i++){
            if(i <= k){
                time = time + min(tickets[k], tickets[i]);
            }
            else{
                time = time + min(tickets[k]-1, tickets[i]);
            }
        }
        return time;
    }
};