//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string convertToRoman(int n) {
        // code here
        string s = "";
        while(n>=1000){
            s += 'M';
            n -= 1000;
        }
        if(n>=900){
            s += "CM";
            n-=900;
        }
        if(n>=500){
            s += 'D';
            n -= 500;
        }
        if(n>=400){
            s += "CD";
            n-=400;
        }
        while(n>=100){
            s += 'C';
            n-=100;
        }
        if(n%100>=90){
            s += "XC";
            n-=90;
        }
        if(n>=50){
            s+= 'L';
            n-=50;
        }
        if(n%50>=40){
            s += "XL";
            n-=40;
        }
        while(n>=10){
            s += 'X';
            n-=10;
        }
        if(n%10==9){
            s += "IX";
            n-=9;
        }
        if(n>=5){
            s += 'V';
            n-=5;
        }
        if(n==4){
            s += "IV";
            return s;
        }
        while(n>0){
            s += 'I';
            n--;
        }
        return s;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	}
	return 0;
}
// } Driver Code Ends