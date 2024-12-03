//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int minChar(string& s) {
        // Step 1: Get the length of the original string
        int n = s.length();

        // Step 2: Create a new string with the original, separator, and reverse
        string rev = s; // Copy the original string
        reverse(rev.begin(), rev.end()); // Reverse it
        string newS = s + "#" + rev; // Concatenated string with separator

        // Step 3: Initialize the LPS (Longest Prefix Suffix) array
        int m = newS.length();
        vector<int> lps(m, 0); // Default all values to 0
        int i = 1, len = 0; // i is the current index, len is the length of the prefix

        // Step 4: Build the LPS array using KMP logic
        while (i < m) {
            if (newS[i] == newS[len]) {
                // If characters match, extend the current prefix
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0) {
                    // If mismatch, fallback to the previous longest prefix
                    len = lps[len - 1];
                } else {
                    // No prefix match, set LPS to 0
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Step 5: Calculate the minimum characters to add
        int longest_palindromic_suffix = lps.back(); // Last value in LPS array
        return n - longest_palindromic_suffix;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends