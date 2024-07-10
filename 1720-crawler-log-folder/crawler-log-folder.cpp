class Solution {
public:
    int minOperations(vector<string>& logs) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = 0;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
               n = max(n-1,0);
            } else if (logs[i] != "./") {
                n++;
            }
        }
        return n;
    }
};