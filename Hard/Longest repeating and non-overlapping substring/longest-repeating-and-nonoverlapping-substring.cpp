//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    string longestSubstring(string s, int n) {
        string res;
        
        for(int i = 0, j = 0; j < n; j++) {
            string str = s.substr(i, j - i + 1);
            if(s.find(str, j + 1) !=  -1 && ( (j - i + 1) > res.length() ) ) // find(string, initial position to start begin)
                res = str;
            else
                i++;
        }
        
        return res == "" ? "-1" : res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends