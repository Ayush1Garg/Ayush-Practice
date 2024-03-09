//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// class Solution{
//   public:
//     char nthCharacter(string s, int r, int n) {
//         //code here
//         string changed = "", orig = s;
//         int len = pow(2,r);
//         char ex = s[n/len]
//     }
// };

class Solution{
    bool util(string &s, int r, int n){
        if(r==0 or n==0) return s[n]-'0'; // converting  returning char value in bool format
        bool res = util(s, r-1, n/2);
        return n%2==0 ?  res : !res;
    }
  public:
    char nthCharacter(string s, int r, int n) {
        return util(s, r, n)+'0'; // converting  returned bool value to char
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends