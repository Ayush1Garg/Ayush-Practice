//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int brute(int n, int m, vector<vector<int>> a) 
    {
        int maxi=-1;
        int temp;
        
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                temp=0;
                
                if( i-1>=0 && j-1>=0 && i+1<n && j+1<m )
                {
                    
                    temp+=a[i-1][j-1];
                    temp+=a[i-1][j];
                    temp+=a[i-1][j+1];
                    temp+=a[i+1][j+1];
                    temp+=a[i+1][j];
                    temp+=a[i+1][j-1];
                    temp+=a[i][j];
                    
                }
                maxi=max(temp,maxi);
            }
        }
        return maxi;    
    }
    
    int brute2(int n, int m, vector<vector<int>> a) 
    {
        int maxi=-1;
        int temp;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                temp=0;
                
                if( i-1>=0 && j-1>=0 && i+1<n && j+1<m )
                {
                    int dx[]={-1,-1,-1,1,1,1,0,};
                    int dy[]={-1,0,1,1,0,-1,0};
                    
                    for(int k=0;k<6;k++)
                    {
                        int r=i+dx[k];
                        int c=j+dy[k];
                        
                        temp+=a[r][c];
                    }
                    temp+=a[i][j];
                
                }
                maxi=max(temp,maxi);
            }
        }
        return maxi;    
    }
  
    int findMaxSum(int n, int m, vector<vector<int>> a)
    {
        if(n<3) return -1;
        return brute(n,m,a);
    }
    // int findMaxSum(int n, int m, vector<vector<int>> mat) {
    //     // code here
    // }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends