//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        int i=0;
        while (x[i]!='\0'){
            if( (x[i]=='(') || (x[i]=='[') || (x[i]=='{') )
            st.push(x[i]);
            else if(x[i]==')'){
                if(st.empty() || st.top()!='(')
                {
                    return false;
                }
                else
                st.pop();
            }
            else if(x[i]==']'){
                if(st.empty() || st.top()!='[')
                {
                    return false;
                }
                else
                st.pop();
            }
            else{
                if(st.empty() || st.top()!='{')
                {
                    return false;
                }
                else
                st.pop();
            }
            i++;
        }
        if(st.empty())
        return true;
        return false;
    }

};


//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends