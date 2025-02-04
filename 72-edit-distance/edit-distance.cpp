class Solution {
private:
    inline int minCost(int x, int y, int z) {
        return min(min(x, y), z);
    }
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        vector<vector<int>> dp(2, vector<int>(len2+1));
        for (int j = 0; j <= len2; j++) {
            dp[0][j] = j;
        }

        int prev = 0;
        int curr;
        for (int i = 1; i <= len1; i++) {
            curr = prev ^ 1;
            dp[curr][0] = i;
            for (int j = 1; j <= len2; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[curr][j] = dp[prev][j-1];
                else
                    dp[curr][j] = minCost(dp[prev][j], dp[curr][j-1], dp[prev][j-1]) + 1;
            }
            prev ^= 1;
        }
        
        return dp[curr][len2];
    }
};