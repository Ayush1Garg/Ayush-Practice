//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sum1 = 0, sum2 = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum1 += a[i];
            sum2 += (long long)i*a[i];
        }
        sum = max(sum,sum2);
        for(int i=0; i<n; i++){
            sum2 = sum2 - sum1 + a[i] + (long long)(n-1)*a[i];
            sum = max(sum2,sum);
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends