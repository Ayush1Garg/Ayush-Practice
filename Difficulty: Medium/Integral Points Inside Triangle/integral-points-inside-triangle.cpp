//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    // Function to calculate the Greatest Common Divisor (GCD) of two numbers
    long long int gcd(long long int a, long long int b) {
        while (b != 0) {
            long long int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to calculate the doubled area of the triangle using Shoelace formula
    // Doubled to avoid dealing with floating-point division
    long long int triangleArea2x(long long int p[], long long int q[], long long int r[]) {
        return abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1]));
    }

    // Function to calculate the number of lattice points on the boundary of the triangle
    long long int boundaryPoints(long long int p[], long long int q[], long long int r[]) {
        return gcd(abs(p[0] - q[0]), abs(p[1] - q[1])) +  // Edge between p and q
               gcd(abs(q[0] - r[0]), abs(q[1] - r[1])) +  // Edge between q and r
               gcd(abs(r[0] - p[0]), abs(r[1] - p[1]));   // Edge between r and p
    }

    // Function to calculate the number of internal lattice points using Pick's Theorem
    long long int InternalCount(long long int p[], long long int q[], long long int r[]) {
        long long int area2x = triangleArea2x(p, q, r);  // Doubled area
        long long int boundaryPointsCount = boundaryPoints(p, q, r);  // Number of boundary points
        return (area2x - boundaryPointsCount + 2) / 2;  // Applying Pick's Theorem formula
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends