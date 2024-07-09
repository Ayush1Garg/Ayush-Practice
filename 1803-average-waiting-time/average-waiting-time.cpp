class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long int endTime = 0, waitTime = 0., n = customers.size();
        for(int i=0; i<n; i++){
            endTime = max(endTime,(long long int)customers[i][0]) + customers[i][1];
            waitTime += endTime - customers[i][0];
        }
        return (1.0*waitTime)/n;
    }
};