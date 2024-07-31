class Solution {
public:
    int solve(int ind, int n, vector<int>& dp, vector<vector<int>>& books, int shelfWidth) {
        if (ind == n) return 0; // Base case: no books left

        if (dp[ind] != 1e9) return dp[ind]; // Memoization check

        int width = 0, height = 0, minHeight = INT_MAX;

        for (int i = ind; i < n; ++i) {
            width += books[i][0];
            if (width > shelfWidth) break; // Exceeds shelf width

            height = max(height, books[i][1]);
            minHeight = min(minHeight, height + solve(i + 1, n, dp, books, shelfWidth));
        }

        return dp[ind] = minHeight;
    }
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n,1e9);
        return solve(0,n,dp,books,shelfWidth);
    }
};