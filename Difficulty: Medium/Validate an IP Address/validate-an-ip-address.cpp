//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        int n = str.size();
        if (n < 7 || n > 15) return false;  // Quick check based on size constraints
        
        // Split the string by '.'
        vector<string> parts;
        stringstream ss(str);
        string part;
        while (getline(ss, part, '.')) {
            parts.push_back(part);
        }

        // There should be exactly 4 parts
        if (parts.size() != 4) return false;

        // Check each part
        for (string part : parts) {
            if (part.empty() || part.size() > 3) return false;

            // Check for leading zeros
            if (part[0] == '0' && part.size() > 1) return false;

            // Check if the part is a number and in range 0-255
            for (char ch : part) {
                if (!isdigit(ch)) return false;
            }

            int num = stoi(part);
            if (num < 0 || num > 255) return false;
        }

        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends