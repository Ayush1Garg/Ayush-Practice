//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        int i=0, j=0, dir = 1;
        // dir = 1 - right, 2 - bottom, 3 - left, 0 - top
        while(i>=0 && j>=0 && i<n && j<m){
            if(matrix[i][j]==1){
                dir = (dir+1)%4;
                matrix[i][j] = 0;
            }
            if(dir==1){
                if(j==m-1) return {i,j};
                j++;
            }
            else if(dir==2){
                if(i==n-1) return {i,j};
                i++;
            }
            else if(dir==3){
                if(j==0) return {i,j};
                j--;
            }
            else{
                if(i==0) return {i,j};
                i--;
            }
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends