class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr, vector<int>& arr2) {
        int n = arr.size(), m = arr2.size();
        if(n==m) return arr2;
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        unordered_map<int,int> freq1;
        unordered_map<int,bool> hash2;
        vector<int> arr1 = arr;
        for(int i=0; i<m; i++){
            hash2[arr2[i]] = true;
        }
        for(int i=0; i<n; i++){
            freq1[arr1[i]]++;
            if( hash2[arr1[i]] ) arr1[i] = -1;
        }
        sort(arr1.begin(),arr1.end());
        int i=0, j=0;
        while(i<n && j<m){
            while(freq1[arr2[j]]>0){
                arr1[i] = arr2[j];
                i++;
                freq1[arr2[j]]--;
            }
            j++;
        }
        return arr1;
    }
};