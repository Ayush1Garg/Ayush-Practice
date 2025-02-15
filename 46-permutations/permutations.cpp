class Solution {
public:
    void comb(int idx, vector<vector<int>>& ans, vector<int>& nums){
        if(idx == nums.size()){
            ans.push_back(nums); // Add the current permutation to the result \U0001f4be
            return;
        }
        for(int i = idx; i < nums.size(); i++){
              swap(nums[idx], nums[i]); // Swap elements to generate new permutation \U0001f504
              comb(idx + 1, ans, nums); // Recurse to the next level \U0001f504
              swap(nums[idx], nums[i]); // Backtrack by restoring the original list ⬅️
            }
        }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; // Store the result (list of permutations) \U0001f4be
        comb(0, ans, nums); // Start the recursive backtracking \U0001f504
        return ans; // Return the list of all permutations ✅
    }
};