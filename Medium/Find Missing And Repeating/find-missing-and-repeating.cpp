//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        long long sum;
        if(n%2==1){
            sum = ( (n+1)/2 )*n;
        }
        else{
            sum = (n/2)*(n+1);
        }
        int rep, mis;
        for(int i=0; i<n; i++){
            // arr[arr[i]] += n;
            sum -= arr[i];
            arr[i]--;
        }
        for(int i=0; i<n; i++){
            arr[arr[i]%n] += n;
            if( (arr[arr[i]%n]/n) >1 ){
                rep = arr[i]%n + 1;
                break;
            }
        }
        // long long mis = (n*(n+1))/2 - sum + rep;
        mis = sum + rep;
        return{rep,mis};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends