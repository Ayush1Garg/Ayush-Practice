//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int left = 0;
        int right = n - 1;
        int left_max = 0;
        int  right_max = 0;
        int  water = 0;
        while(left <= right){
            if(arr[left] <= arr[right]){
                if (arr[left] > left_max){
                    left_max = arr[left];
                }
                else{
                    water += left_max - arr[left];
                }
                left += 1;
            }
            else{
                if(arr[right] > right_max){
                    right_max = arr[right];
                }
                else{
                    water += right_max - arr[right];
                }
                right -= 1;
            }
        }
        return water;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends