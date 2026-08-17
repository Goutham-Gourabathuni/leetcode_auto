class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        
        function<int(int, int)> dfs = [&](int left, int right) {
            if (left == right) return 0;
            if (memo[left][right] != 0) return memo[left][right];
            int ans = 0;
            for (int i = left; i < right; i++) {
                int leftSum = prefixSum[i + 1] - prefixSum[left];
                int rightSum = prefixSum[right + 1] - prefixSum[i + 1];
                if (leftSum < rightSum) ans = max(ans, leftSum + dfs(left, i));
                else if (leftSum > rightSum) ans = max(ans, rightSum + dfs(i + 1, right));
                else ans = max({ans, leftSum + dfs(left, i), leftSum + dfs(i + 1, right)});
            }
            return memo[left][right] = ans;
        };
        return dfs(0, n - 1);
    }
};