//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_map<int,int> mp;
      int mi = INT_MAX, ma = INT_MIN;
      for(int i=0; i<N; i++){
          mp[arr[i]]++;
          mi = min(mi, arr[i]);
          ma = max(ma, arr[i]);
      }
      int len=0, mlen=0;
      for(int i= mi; i<=ma; i++){
          if(mp.find(i)!=mp.end()){
              len++;
          }
          else{
              mlen = max(len, mlen);
              len=0;
          }
      }
      mlen = max(len,mlen);
      return mlen;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends