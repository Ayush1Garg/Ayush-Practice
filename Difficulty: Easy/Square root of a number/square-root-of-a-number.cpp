//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        long long int low = 1, high = n;
        while(low<=high){
            long long int mid = (high-low)/2 + low;
            long long prod = mid*mid;
            // cout<<mid<<" "<<prod;
            if(prod==n) return mid;
            if(prod>n){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends