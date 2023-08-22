//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<vector<int>> sum(n,vector<int>(2,0));
        int msum = 0, tsum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum[i][0] += matrix[i][j];
                sum[j][1] += matrix[i][j];
                msum = max(msum,max(sum[i][0],sum[j][1]));
                tsum += matrix[i][j];
            }
        }
        return (n*msum - tsum);
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends