//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


void printKAlmostPrimes(int k, int n);

int main() {
	// your code goes herei
int t;
cin>>t;
while(t--){
	int n,k;
	cin>>n>>k;
    printKAlmostPrimes(n,k);
    cout<<endl;
}


	return 0;
}
// } Driver Code Ends

bool isprime(int n){
    if(n<2)
    return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0)
        return false;
    }
    return true;
}

int cntpf(int n, int k){
    if(n==2 || n==3 || n==5 || n==7)
    return 1;
    int ans =0;
    while(n%2==0){
        n = n/2;
        ans++;
    }
    for(int i=3; i<=sqrt(n); i+=2){
        while(n%i==0){
            n = n/i;
            ans++;
        }
    }
    if(n>2)
    ans++;
    
    return ans;
}

/*You are required to complete this function*/
void printKAlmostPrimes(int k, int n)
{
    //Your code here
    int num =2;
    while(n>0){
        int divs = cntpf(num,k);
        if(divs==k){
            cout<<num<<" ";
            n--;
        }
        num++;
    }
    
    
}