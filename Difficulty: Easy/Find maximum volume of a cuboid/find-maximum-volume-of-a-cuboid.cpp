//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to compute the optimal length l
    double length(double perimeter, double area) {
        // Calculate length using the derived formula
        double l = (perimeter - std::sqrt((perimeter * perimeter) - (24 * area))) / 12;
        return l;
    }

    // Function to compute the maximum volume V
    double maxVolume(double perimeter, double area) {
        // Compute the optimal length l
        double l = length(perimeter, area);
        
        // Calculate the volume using the computed length l
        double volume = ((perimeter * l * l) - (8 * l * l * l)) / 4;
        return volume;
    }
};

//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends