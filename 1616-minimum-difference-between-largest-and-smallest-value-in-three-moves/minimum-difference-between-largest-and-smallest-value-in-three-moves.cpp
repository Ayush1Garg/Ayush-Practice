class Solution {
public:

    // nums: integer array
    // one move can choose nums[i] and change it to any value

    // Return: min difference between largest and smallest value of nums after performing at most 3 moves

    // Constraints:

    // 1 <= nums.length <= 10^5
    // -10^9 <= nums[i] <= 10^9

    // O(n). Get the max 4 and min 4 elements
    

    int minDifference(vector<int>& nums)
    {
#if 1
        // Simplify code
        // O(n). Get the max 4 and min 4 elements
        if (nums.size() <= 4)
        {
            return 0;
        }

        std::nth_element(nums.begin(), nums.begin() + 4, nums.end());
        std::nth_element(nums.begin() + 4, nums.end() - 4, nums.end());
        std::sort(nums.begin(), nums.begin() + 4);
        std::sort(nums.end() - 4, nums.end());


        int min = INT_MAX;

        for (int left = 0; left <= 3; ++left)
        {
            int right = 3 - left;
            min = std::min(min, std::abs(nums[nums.size() - 1 - right] - nums[left]));
        }

        return min;




#endif

#if 0
        // O(n log n). Sort and check the min diff between max and min elements
        // 54 ms 96.84 %, 38.81 MB 16.64 %
        int n = nums.size();

        if (n <= 4)
        {
            return 0;
        }

        int minDiff = INT_MAX;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i <= 3; i++)
        {
            minDiff = min(minDiff, (nums[n - 4 + i] - nums[i]));
        }

        return minDiff;
#endif
    }
};