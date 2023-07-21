//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    
    // Function to merge two sorted subarrays and count inversions
    long long int merge(long long arr[], long long left, long long mid, long long right) {
        
        long long int countInversion = 0;
        long long sizeOfLeft = mid - left + 1;
        long long sizeOfRight = right - mid;
        
        // Create temporary arrays for the left and right subarrays
        long long *leftArray = new long long[sizeOfLeft];
        long long *rightArray = new long long[sizeOfRight];
        
        // Copy elements from the original array to the left subarray
        for(auto i = 0; i < sizeOfLeft; i++)
            leftArray[i] = arr[left + i];
        
        // Copy elements from the original array to the right subarray
        for(auto j = 0; j < sizeOfRight; j++)
            rightArray[j] = arr[mid + 1 + j];
            
        long long leftIndex = 0, rightIndex = 0, mergedIndex = left;
        
        // Merge the left and right subarrays while counting inversions
        while(leftIndex < sizeOfLeft && rightIndex < sizeOfRight){
            if(leftArray[leftIndex] <= rightArray[rightIndex]){
                arr[mergedIndex] = leftArray[leftIndex];
                leftIndex++;
            }
            else{
                arr[mergedIndex] = rightArray[rightIndex];
                // If an element from the right subarray is smaller than an element
                // from the left subarray, it forms inversions with all remaining
                // elements in the left subarray.
                countInversion += (sizeOfLeft - leftIndex);
                rightIndex++;
            }
            mergedIndex++;
        }
        
        // Copy any remaining elements from the left subarray
        while(leftIndex < sizeOfLeft){
            arr[mergedIndex] = leftArray[leftIndex];
            leftIndex++;
            mergedIndex++;
        }
        
        // Copy any remaining elements from the right subarray
        while(rightIndex < sizeOfRight){
            arr[mergedIndex] = rightArray[rightIndex];
            rightIndex++;
            mergedIndex++;
        }
        
        // Free the memory allocated for the temporary arrays
        delete[] leftArray;
        delete[] rightArray;
        
        return countInversion;
    }
    
    // Function to perform modified merge sort and count inversions
    long long int modifiedMergeSort(long long arr[], long long left, long long right) {
        
        long long int mid, countInversion = 0;
        
        if(right > left){
            mid = (left + right) >> 1;
            
            // Recursively divide the array into two halves and count inversions
            countInversion += modifiedMergeSort(arr, left, mid);
            countInversion += modifiedMergeSort(arr, mid + 1, right);
            
            // Merge the two sorted halves and count inversions
            countInversion += merge(arr, left, mid, right);
        }
        
        return countInversion;
    }
    
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return modifiedMergeSort(arr,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends