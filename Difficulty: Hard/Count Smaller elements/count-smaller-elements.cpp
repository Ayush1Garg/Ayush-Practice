//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
    public:
    void merge(int start, int mid, int end, vector<int>& arr, vector<int>& count, vector<int>& index) {
        int n = end - start + 1;
        vector<int> newIndex(n);
        int left = start, right = mid + 1, sortedPos = 0, rightCount = 0;

        while (left <= mid && right <= end) {
            if (arr[index[right]] < arr[index[left]]) {
                newIndex[sortedPos++] = index[right++];
                rightCount++;
            } else {
                count[index[left]] += rightCount;
                newIndex[sortedPos++] = index[left++];
            }
        }

        while (left <= mid) {
            count[index[left]] += rightCount;
            newIndex[sortedPos++] = index[left++];
        }

        while (right <= end) {
            newIndex[sortedPos++] = index[right++];
        }

        for (int i = 0; i < n; i++) {
            index[start + i] = newIndex[i];
        }
    }

    void mergeSort(int start, int end, vector<int>& arr, vector<int>& count, vector<int>& index) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        mergeSort(start, mid, arr, count, index);
        mergeSort(mid + 1, end, arr, count, index);
        merge(start, mid, end, arr, count, index);
    }

    vector<int> constructLowerArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(n, 0);
        vector<int> index(n);

        for (int i = 0; i < n; i++) {
            index[i] = i;
        }

        mergeSort(0, n - 1, arr, count, index);

        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends