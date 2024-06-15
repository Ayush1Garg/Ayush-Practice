//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
    
        vector<vector<int>> neighbors = {
        {0, 8},        // Neighbors of 0
        {1, 2, 4},     // Neighbors of 1
        {2, 1, 3, 5},  // Neighbors of 2
        {3, 2, 6},     // Neighbors of 3
        {4, 1, 5, 7},  // Neighbors of 4
        {5, 2, 4, 6, 8},// Neighbors of 5
        {6, 3, 5, 9},  // Neighbors of 6
        {7, 4, 8},     // Neighbors of 7
        {8, 0, 5, 7, 9},// Neighbors of 8
        {9, 6, 8}      // Neighbors of 9
        };

        // If n is 1, we can have 10 possible sequences (0 to 9)
        if (n == 1) return 10;
    
        // dp table to store the number of sequences ending at each digit for each length
        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
    
        // Initialize the dp table for sequences of length 1
        for (int i = 0; i < 10; ++i) {
            dp[1][i] = 1;
        }
    
        // Fill the dp table for lengths from 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int digit = 0; digit < 10; ++digit) {
                dp[len][digit] = 0;
                for (int neighbor : neighbors[digit]) {
                    dp[len][digit] += dp[len - 1][neighbor];
                }
            }
        }
    
        // Sum up all sequences of length n
        long long totalCount = 0;
        for (int i = 0; i < 10; ++i) {
            totalCount += dp[n][i];
        }
    
        return totalCount;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends