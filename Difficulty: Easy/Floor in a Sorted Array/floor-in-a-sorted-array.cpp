//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {

        // Your code here
        long long high = n-1, low = 0;
        while(high>=low){
            long long mid = (high-low)/2 + low;
            if(v[mid]==x) return mid;
            if(v[mid]>x) high = mid-1;
            else low = mid+1;
        }
        return high;
    }
};


//{ Driver Code Starts.

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends