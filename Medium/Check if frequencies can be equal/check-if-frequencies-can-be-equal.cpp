//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    vector<int> freq(26,0);
	    for(auto i:s){
	        freq[i-'a']++;
	        
	    }
	    sort(freq.begin(),freq.end());
	    int l=upper_bound(freq.begin(),freq.end(),0)-freq.begin();
	    int r=25;//find the occurrence of the first frequency and place the left and right pointers
	    int diff=0;
        int n=r-l+1;
	    while(l<r)
	    {
	        diff+=freq[r]-freq[l]; //accumulate the difference
	        l++,r--;
	    }
        if(n==3 && freq[r-1]==1 && freq[r]==freq[r+1])
        return 1;
        else if(n==3 && freq[r-1]<freq[r])
        return 0;      
        return diff<=1;//return the final answer
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends