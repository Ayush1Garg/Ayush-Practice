//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

void transpose(vector<vector<int>>& mat){
    int n = mat.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
}

void mirror(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m/2; j++){
            swap(mat[i][j],mat[i][m-1-j]);
        }
    }
}

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    transpose(mat);
    mirror(mat);
}


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends