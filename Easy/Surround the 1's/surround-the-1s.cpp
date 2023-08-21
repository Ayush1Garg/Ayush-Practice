//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int zeroes(vector<vector<int>> &matrix, int i, int j, int n, int m){
        int cnt = 0;
        if(i>0){
            cnt += !matrix[i-1][j];
            if(j>0) cnt += !matrix[i-1][j-1];
            if(j<m-1) cnt += !matrix[i-1][j+1];
        }
        if(i<n-1){
            cnt += !matrix[i+1][j];
            if(j>0) cnt += !matrix[i+1][j-1];
            if(j<m-1) cnt += !matrix[i+1][j+1];
        }
        if(j>0) cnt += !matrix[i][j-1];
        if(j<m-1) cnt += !matrix[i][j+1];
        return cnt;
    }
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size(), m = matrix[0].size(), cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]){
                    int val = zeroes(matrix,i,j,n,m);
                    if(val && val%2==0) cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends