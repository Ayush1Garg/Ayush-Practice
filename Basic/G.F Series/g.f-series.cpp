//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void gfSeries(int N, long long int a = 0, long long int b = 1, long long int n1 = 2)
    {
        // Write Your Code here
        if(n1>=N){
            cout<<endl;
            return;
        }
        if(n1==2){
            cout<<a<<" "<<b<<" ";
        }
        long long int c = pow(a,2)-b;
        cout<<c<<" ";
        n1++;
        gfSeries(N,b,c,n1);
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        ob.gfSeries(N);
    }
    return 0;
}
// } Driver Code Ends