//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int largestNum = -1;
        int secondLarg = largestNum;
        
        for(int i = 0; i < arr.size(); i++)
        {
            int item = arr[i];
            if(item > largestNum)
            {
                secondLarg = largestNum;
                largestNum = item;
            }
            else if(item > secondLarg && item < largestNum)
            {
                secondLarg = item;
            }
        }
            
        return secondLarg;
    }
};

//{ Driver Code Starts.

int main() {
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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends