//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<string>  spaceString(char str[]);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[10000];
        cin>>str;
        vector<string> vec = spaceString(str);
        for(string s: vec){
            cout<<s<<"$";
        }
        cout<<endl;
    }

}

// } Driver Code Ends


/*You have to complete this function*/

void help(int i, int space, int n, string ds, string &s, vector<string> &ans){
    if(i==n){
        ans.push_back(ds);
        return;
    }
    help(i+1,0,n,ds+s[i],s,ans);
    if(space==0){
        help(i,1,n,ds+' ',s,ans);
    }
}

vector<string>  spaceString(char str[])
{
    //Your code here
    vector<string> ans;
    string s(str);
    int n = s.length();
    string ds = "";
    char c = s[0];
    ds += c;
    help(1,0,n,ds,s,ans);
    return ans;
}