//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pivot(vector<int>&nums){
        int n = nums.size();
        int s = 0, e = n-1, mid  = s + (e-s)/2;
        while(s  < e){
            if(nums[mid] >= nums[0]){
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s+(e-s)/2;
        }
        return s;
    }
    int binary(vector<int>&nums , int s , int e , int target){
        int mid = s + (e-s)/2;
        while(s<=e){
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e  = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        // Your code here
        int k = pivot(nums), n = nums.size();
        if(nums[k] <= target and target <= nums[n-1] ){
            return binary(nums ,  k ,n-1, target);
        }
        return binary(nums , 0 , k-1, target);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends