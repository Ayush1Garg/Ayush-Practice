//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void print(vector<long long> v, long long n){
        for(long long i=0; i<n; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(),a.end());
        // print(a,n);
        long long i=0, j = m-1, diff=a[n-1];
        while(j<n){
            diff = min(diff,a[j]-a[i]);
            j++;
            i++;
        }
        return diff;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends