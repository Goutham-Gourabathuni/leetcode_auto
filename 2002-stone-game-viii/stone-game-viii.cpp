class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pre(n);
        pre[0] = stones[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + stones[i];
        
        vector<int> f(n);
        f[n - 1] = pre[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            f[i] = max(f[i + 1], pre[i] - f[i + 1]);
        }
        return f[1];
    }
};