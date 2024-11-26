//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int sum1 = 0, sum2 = 0, minsum = arr[0], maxsum = arr[0], tsum = 0;
        for(auto& num : arr){
            tsum += num;
            sum1 += num;
            sum2 += num;
            minsum = min(sum1,minsum);
            maxsum = max(sum2,maxsum);
            if(sum1>0) sum1 = 0;
            if(sum2<0) sum2 = 0;
        }
        return max(maxsum, tsum - minsum);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends