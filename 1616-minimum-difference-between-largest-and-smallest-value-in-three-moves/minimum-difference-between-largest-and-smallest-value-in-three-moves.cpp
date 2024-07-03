static int _ = [](){ std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); return 0;}();
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        }

        std::nth_element(nums.begin(), nums.begin() + 4, nums.end());
        std::nth_element(nums.begin() + 4, nums.end() - 4, nums.end());
        std::sort(nums.begin(), nums.begin() + 4);
        std::sort(nums.end() - 4, nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            //std::cout << nums[i] << " ";
        }

        int min = INT_MAX;
        for (int left = 0; left <= 3; ++left) {
            int right = 3 - left;
            min = std::min(min, std::abs(nums[nums.size() - 1 - right] - nums[left]));
        }

        return min;
    }
};

/*
0,1,5,10,14

10,14  4
5,10   5
1,5   4
0,1   1




*/