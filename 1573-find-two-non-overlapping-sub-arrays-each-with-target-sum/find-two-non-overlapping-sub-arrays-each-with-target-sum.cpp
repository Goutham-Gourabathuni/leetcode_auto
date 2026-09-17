class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        // best[i] = minimum length of a valid subarray
        // completely inside arr[0...i]
        vector<int> best(n, INT_MAX);

        int ans = INT_MAX;

        int left = 0;
        long long sum = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            // Since all numbers are positive, shrink from left
            while (sum > target) {
                sum -= arr[left++];
            }

            // We found a subarray [left...right]
            if (sum == target) {
                int len = right - left + 1;

                // Need another subarray completely before 'left'
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }

                // This is the best valid subarray ending at/before right
                if (right == 0)
                    best[right] = len;
                else
                    best[right] = min(best[right - 1], len);
            }
            else {
                // No new valid subarray ending at right
                if (right > 0)
                    best[right] = best[right - 1];
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};