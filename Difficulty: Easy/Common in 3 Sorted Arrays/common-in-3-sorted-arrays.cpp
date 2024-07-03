//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            set<int> s;
            int a=0,b=0,c=0;
            while(a<n1 and b<n2 and c<n3)
            {
                if(A[a]<B[b] or A[a]<C[c]) a++;
                if(B[b]<A[a] or B[b]<C[c]) b++;
                if(C[c]<A[a] or C[c]<B[b]) c++;
                if(A[a]==B[b] and A[a]==C[c])
                {
                    s.insert(A[a]);
                    a++;b++;c++;
                }
            }
            vector<int> v(s.begin(),s.end());
            if(v.empty()) return {-1};
            return v;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends