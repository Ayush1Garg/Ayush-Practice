//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int a=1; // first  possible missing  number 
        for(auto i:arr){
            
            // if a+k<i condition is true that means a + some k numbers are missing 
            // hence the kth number will be a+k-1
            
            // if a+k==i  means a + k-1 numbers are missing and kth number after a is i 
            // hence after including a the kth missing number is a+k-1
            
            if(a+k<=i) return a+k-1;
            
            // else a+k>i means there are numbers in array in the range [a,a+k) 
            
            k-=i-a;// subtract those numbers that are in range [a,i) from k
            a=i+1;// set a after i
        }
        return a+k-1;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends