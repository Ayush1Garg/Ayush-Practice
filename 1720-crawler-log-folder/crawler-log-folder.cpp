class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = 0;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
               if(n>0) n--;
            } else if (logs[i] == "./") {
                continue;
            } else {
                n++;
            }
        }
        if(n<0) return 0;
        return n;
    }
};