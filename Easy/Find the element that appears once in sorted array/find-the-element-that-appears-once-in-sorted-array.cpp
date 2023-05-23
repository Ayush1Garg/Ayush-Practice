//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int a[], int n)
    {
        //code here
        int i=0, j=1, r=0; 
        while(i<n && j<n){
            if(a[i]==a[j]){
                r=1;
                j++;
            }
            else{
                if(r==1){
                    i = j;
                    j++;
                    r=0;
                }
                else 
                    return a[i];
            }
        }
        if(i == n-1 && j == n){
            return a[i];
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends