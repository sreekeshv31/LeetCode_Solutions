class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        result.reserve(size(nums) / 3);
        for (int i = 0; i < size(nums); i += 3) {
            int diff = nums[i + 2] - nums[i];
            if (diff > k) {
                return {};
            }
            result.emplace_back(nums.begin() + i, nums.begin() + i + 3);
        }
        return result;
    }
};