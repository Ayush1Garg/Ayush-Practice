//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here 
        if(n==1) return matrix[0][0];
        if(n==2) return ( matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0] );
        int det = 0;
        int row, col;
        for(int i=0; i<n; i++){
            vector<vector<int>> v;
            row = 1;
            while(row<n){
                col = 0;
                vector<int> temp;
                while(col<n){
                    if(col!=i){
                        temp.push_back(matrix[row][col]);
                    }
                    col++;
                }
                v.push_back(temp);
                row++;
            }
            if(i%2==0){
                det += matrix[0][i]*determinantOfMatrix(v,n-1);
            }
            else{
                det -= matrix[0][i]*determinantOfMatrix(v,n-1);
            }
        }
        return det;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends