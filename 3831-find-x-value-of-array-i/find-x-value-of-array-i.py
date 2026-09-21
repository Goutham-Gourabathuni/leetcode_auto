class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        result = [0] * k
        dp = [0] * k
        for num in nums:
            next_dp = [0] * k
            next_dp[num % k] += 1
            for r in range(k):
                if dp[r] > 0:
                    new_r = (r * num) % k
                    next_dp[new_r] += dp[r]
            dp = next_dp
            for r in range(k):
                result[r] += dp[r]
        return result