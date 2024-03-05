//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    void print(vector<int> v){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int> left, right;
        int lsize = 1, rsize = 1;
        left.push_back(0);
        right.push_back(n-1);
        for(int i=1; i<n; i++){
            if(a[i]<a[left[lsize-1]]){
                left.push_back(i);
                lsize++;
            }
        }
        for(int i=n-2; i>=0; i--){
            if(a[i]>a[right[rsize-1]]){
                right.push_back(i);
                rsize++;
            }
        }
        // print(left);
        // print(right);
        // cout<<endl;
        int res = 0;
        int i = lsize-1,j = 0;
        while(i>=0 && j<rsize && right[j]>=left[i]){
            // cout<<i<<" "<<j<<endl;
            if(a[left[i]]<=a[right[j]]){
                res = max(res,right[j]-left[i]);
                i--;
            }
            else{
                j++;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends