#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int ans = -1e9;
            ans = max(ans, stoneValue[i] - dp[i + 1]);
            if (i + 1 < n) ans = max(ans, stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            if (i + 2 < n) ans = max(ans, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
            dp[i] = ans;
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};