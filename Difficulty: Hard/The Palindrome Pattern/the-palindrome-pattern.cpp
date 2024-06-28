//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(int i, vector<vector<int>> &v, int n, int iscol=0){
        int x = 0, y = n-1;
        if(iscol){
            while(x<y){
                if(v[x][i] != v[y][i]) return false;
                x++;
                y--;
            }
        }
        else{
            while(x<y){
                if(v[i][x] != v[i][y]) return false;
                x++;
                y--;
            }
        }
        return true;
    }

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        for(int row=0; row<n; row++){
            if(check(row,arr,n,0)){
                return ( to_string(row) + " R" );
            }
        }
        for(int col=0; col<n; col++){
            if(check(col,arr,n,1)) return ( to_string(col) + " C" );
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends