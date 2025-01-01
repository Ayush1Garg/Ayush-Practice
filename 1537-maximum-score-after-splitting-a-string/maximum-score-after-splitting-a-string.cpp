class Solution {
public:
    int maxScore(string s) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int ones = 0;
        int zeros = 0;
        int best = INT_MIN;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }
            
            best = max(best, zeros - ones);
        }
        
        if (s[s.size() - 1] == '1') {
            ones++;
        }
        
        return best + ones;
    }
};