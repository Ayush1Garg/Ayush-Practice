bool compare(const vector<int>& a, const vector<int>& b) { return b[1] > a[1]; }
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<vector<int>> helper(nums.size(), vector<int>(2));
        for (int i = 0; i < nums.size(); i++) {
            helper[i][0] = nums[i];
            helper[i][1] = 0;
            int mul = 1;
            while (true) {
                helper[i][1] += mul * (mapping[nums[i] % 10]);
                nums[i] = nums[i] / 10;
                mul = mul * 10;
                if (nums[i] == 0)
                    break;
            }
        }
        sort(helper.begin(), helper.end(), compare);
        // for(int i=0; i<nums.size(); i++){
        //     cout<<helper[i][0]<<" "<<helper[i][1]<<endl;
        // }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = helper[i][0];
        }
        return nums;
    }
};