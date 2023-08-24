//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
        /*You are required to complete below function */
        string strcon(vector<int> &v){
            string s="";
            for(int i=0; i<v.size(); i++){
                s += char(v[i] + '0');
            }
            return s;
        }
        string multiplyStrings(string s1, string s2) {
            //Your code here
            if(s1=="0"||s2=="0"){
                return "0";
            }
            vector<int> res(s1.length()+s2.length(),0);
            int l1 = s1.length(),l2 = s2.length();
            int n1=0,n2=0,p1=l1-1, p2=l2-1,p=0,pos ,carry=0;
            int stop1=-1, stop2=-1;
            if(s1[0]=='-'){
                stop1++;
                // p1--;
            }
            if(s2[0]=='-'){
                stop2++;
                // p2--;
            }
            while(p1>stop1){
                n1 = s1[p1]-'0';
                pos = p;
                p2 = l2-1;
                while(p2>stop2){
                    n2 = s2[p2]-'0';
                    carry += n1*n2 + res[pos];
                    res[pos] = carry%10;
                    carry = carry/10;
                    pos++;
                    p2--;
                }
                while(carry>0){
                    carry += res[pos];
                    res[pos] = carry%10;
                    carry /= 10;
                    pos++;
                }
                p++;
                p1--;
            }
            int l = res.size();
            while(res[l-1]==0){
                res.pop_back();
                l--;
            }
            string ans = strcon(res);
            if(stop1+stop2==-1){
                ans += '-';
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
};


//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends