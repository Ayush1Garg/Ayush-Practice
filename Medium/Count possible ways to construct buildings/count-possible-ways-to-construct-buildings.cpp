//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N) {
        const int mod = 1000000007;
        int prev = 1, curr = 1;

        for (int i = 0; i < N; ++i) {
            int temp = curr;
            curr = (prev + curr) % mod;
            prev = temp;
        }

        return (static_cast<long long>(curr) * curr) % mod;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends