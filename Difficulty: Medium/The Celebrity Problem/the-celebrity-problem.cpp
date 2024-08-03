//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        for(int j=0; j<m; j++){
            bool found = true;
            for(int i=0; i<n; i++){
                if(mat[i][j]==0 && i!=j){
                    found = false;
                    break;
                }
            }
            if(found){
                bool noKnown = true;
                for(int i=0; i<m; i++){
                    if(mat[j][i]==1){
                        noKnown = false;
                        break;
                    }
                }
                if(noKnown) return j;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends