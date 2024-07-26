//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        int minele = INT_MAX;
        for(int i=0; i<n; i++){
            if(arr[i]>0) minele = min(minele,arr[i]);
        }
        if(minele>1) return 1;
        for(int i=0; i<n; i++){
            if(arr[i]<=0 || arr[i]>n){
                arr[i] = minele;
            }
        }
        for(int i=0; i<n; i++){
            // cout<<abs(arr[i])-1<<" "<<arr[abs(arr[i])-1]<<" & ";
            arr[abs(arr[i])-1] = -1*abs(arr[abs(arr[i])-1]);
            // cout<<abs(arr[i])-1<<" "<<arr[abs(arr[i])-1]<<endl;
        }
        for(int i=0; i<n; i++){
            if(arr[i]>0) return i+1;
        }
        return n+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends