//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int k) {
        // complete the function here
        int n = arr.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (high+low)/2;
            if(arr[mid]==k) return mid;
            if(arr[low]<=arr[mid]){
                if(arr[low]<=k && k<=arr[mid]){
                    high = mid-1;
                }
                else low = mid+1;
            }
            else{
                if(arr[mid]<=k && k<=arr[high]){
                    low = mid+1;
                }
                else high = mid-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends