//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int maxLen = 0, negCount = 0, prevZero = -1, firstNeg = -1;
            for (int index = 0; index < n; index++){
                if (arr[index] < 0){
                    negCount++;
                    if (firstNeg == -1){
                        firstNeg = index;
                    }
                }
                if (arr[index] == 0){
                    firstNeg = -1;
                    negCount = 0;
                    prevZero = index;
                }
                else {
                    if (negCount % 2 == 0){
                        maxLen = max(maxLen,index - prevZero);
                    }
                    else{
                        maxLen = max(maxLen,index - firstNeg);
                    }
                }
            }
            return maxLen;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends