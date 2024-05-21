//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        int i = lower_bound(arr.begin(),arr.end(),x) - arr.begin(), j, d1, d2;
        if(arr[i]==x){
            j = i+1;
            i = i-1;
        }
        else{
            j = i;
            i = i-1;
        }
        vector<int> ans;
        while(k>0){
            if(i<0){
                while(k>0){
                    ans.push_back(arr[j]);
                    j++;
                    k--;
                }
                break;
            }
            else if(j>=n){
                while(k>0){
                    ans.push_back(arr[i]);
                    i--;
                    k--;
                }
                break;
            }
            else{
                d1 = x - arr[i];
                d2 = arr[j] - x;
                if(d1<d2){
                    ans.push_back(arr[i--]);
                    k--;
                }
                else{
                    ans.push_back(arr[j++]);
                    k--;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends