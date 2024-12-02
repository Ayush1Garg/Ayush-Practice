//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // Concatenate pattern and text with a unique delimiter
        string newS = pat + "#" + txt;
        
        // Initialize the LPS (Longest Prefix Suffix) array
        vector<int> lps(newS.length());
        int len = 0; // Length of the previous longest prefix
        int i = 1;   // Start from the second character

        // Build the LPS array
        while (i < newS.length()) {
            if (newS[i] == newS[len]) {
                // If characters match, extend the prefix
                ++len;
                lps[i] = len;
                ++i;
            } else {
                // Mismatch: Use the previously computed LPS value
                if (len > 0) {
                    len = lps[len - 1];
                } else {
                    // No prefix match
                    lps[i] = 0;
                    ++i;
                }
            }
        }

        // Find pattern matches in the text using the LPS array
        vector<int> ans;
        int pattLength = pat.length() + 1; // Offset due to delimiter
        for (int idx = pattLength; idx < lps.size(); ++idx) {
            if (lps[idx] == pat.length()) {
                // Calculate the starting index in the original text
                ans.push_back(idx - pattLength - lps[idx] + 1);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends