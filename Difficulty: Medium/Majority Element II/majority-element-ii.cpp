//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        vector<int>ans;
        int n=nums.size(),cand1,cand2=0,counter1=0,counter2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand1){
                counter1++;
            }else if(nums[i]==cand2){
                counter2++;
            }else if(counter1==0){
                cand1=nums[i];
                counter1++;
            }else if(counter2==0){
                cand2=nums[i];
                counter2++;
            }else {
                counter1--;
                counter2--;
            }
        }
        // now cand1 and cand2 is the potential winner so at last 
        // veriry wheather they are majority element or not;
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand1) count1++;
            else if(nums[i]==cand2) count2++;
        }
        if(count1>(n/3)) ans.push_back(cand1);
        if(count2>(n/3)) ans.push_back(cand2);
        // sort the elements of ans vector (there will be maximum 2 elements so no issue for the time complexity)
        sort(ans.begin(),ans.end());  
        // finally return the ans;
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends