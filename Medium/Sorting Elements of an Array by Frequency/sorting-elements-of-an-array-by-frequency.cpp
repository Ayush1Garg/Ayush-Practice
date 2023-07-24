#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &v1, const vector<int> &v2){
    if(v1[1]>v2[1]){
        return true;
    }
    if(v1[1]==v2[1]){
        return v1[0]<v2[0];
    }
    return false;
}

void printArray(int ar[], int n){
    for(int i=0; i<n; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

void solution(int arr[], int n){
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        if( mp.find((arr[i])) != mp.end() ){
            v.push_back({arr[i],mp[arr[i]]});
            mp.erase(arr[i]);
        }
    }
    sort(v.begin(),v.end(),compare);
    int i=0,j=0;
    while(i<n && j<v.size()){
        while(v[j][1]>0){
            arr[i] = v[j][0];
            v[j][1]--;
            i++;
        }
        j++;
    }
    printArray(arr,n);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t>0){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n; i++){
	        cin>>a[i];
	    }
	    solution(a,n);
	    t--;
	}
	return 0;
}