//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        // code here
        int n = nums.size();
        if(n==2){
            return {nums[1],nums[0]};
        }
        vector<long long int> ans(n,0);
        long long int prod = 1, zer = 0;
        // cout<<"@# ";
        for(int i=0; i<n; i++){
            if(nums[i] == 0) zer++;
            else prod = prod*nums[i];
            if(zer>1) return ans;
            // cout<<prod<<" ";
        }
        // cout<<endl;
        for(int i=0; i<n; i++){
            if(nums[i]==0) ans[i] = prod;
            else ans[i] = zer==1 ? 0 : prod/nums[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends