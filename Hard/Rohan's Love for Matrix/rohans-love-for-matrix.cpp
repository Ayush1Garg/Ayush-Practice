//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod=1000000007;
    int firstElement(int n) {
        int first=1,sec=1,sum=1;
        for(int i=0;i<n-2;i++)
        {
            sum=(first%mod)+(sec%mod);
            first=sec%mod;
            sec=sum%mod;
        }
        return sum%mod;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends