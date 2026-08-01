class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return maxDiff(nums, 0, n - 1, memo) >= 0;
    }

    int maxDiff(vector<int>& nums, int left, int right, vector<vector<int>>& memo) {
        if (left == right) return nums[left];
        if (memo[left][right] != -1) return memo[left][right];

        int pickLeft = nums[left] - maxDiff(nums, left + 1, right, memo);
        int pickRight = nums[right] - maxDiff(nums, left, right - 1, memo);

        return memo[left][right] = max(pickLeft, pickRight);
    }
};