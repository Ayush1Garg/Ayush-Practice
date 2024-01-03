//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int smallestSubstring(string input_string) {
        std::vector<int> last_occurrence(3, -1);  // To store the last occurrence index of each character
        int string_length = input_string.length();
        int minimum_length = INT_MAX;  // Initialize with infinity as a placeholder for the minimum length

        // Iterate through the characters in the input string
        for (int current_index = 0; current_index < string_length; ++current_index) {
            // Update the last occurrence index for the current character
            last_occurrence[static_cast<int>(input_string[current_index]) - '0'] = current_index;

            // Find the minimum index among the last occurrences
            int min_occurrence = *min_element(last_occurrence.begin(), last_occurrence.end());

            // Update the minimum length if a valid substring is found
            if (min_occurrence != -1) {
                minimum_length = std::min(minimum_length, current_index - min_occurrence + 1);
            }
        }

        // Return -1 if no valid substring is found, otherwise return the minimum length
        return (minimum_length == INT_MAX) ? -1 : minimum_length;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends