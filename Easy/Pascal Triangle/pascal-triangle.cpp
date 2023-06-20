//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<ll>> pst;
        vector<ll> line;
        ll temp;
        int mod = 1000000007;
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(j==0 || j==i-1){
                    // line.push_back(1);
                    temp = 1;
                }
                else{
                    // line.push_back(pst[i-1][j-1] + pst[i-1][j]);
                    temp = (pst[i-2][j-1] + pst[i-2][j]) % mod;
                }
                line.push_back(temp);
            }
            pst.push_back(line);
            line.clear();
        }
        return pst[n-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends