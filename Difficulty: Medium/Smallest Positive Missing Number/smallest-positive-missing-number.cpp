//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        for(auto& num : arr){
            if(num<1 || num>n) num = n+1;
        }
        for(int i=0; i<n; i++){
            int index = abs(arr[i]) - 1;
            if(index==n) continue;
            arr[index] = -1*abs(arr[index]);
        }
        for(int i=0; i<n; i++){
            if(arr[i]>0) return i+1;
        }
        return n+1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends