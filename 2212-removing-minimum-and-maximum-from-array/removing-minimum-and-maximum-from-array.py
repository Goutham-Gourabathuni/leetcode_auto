class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        minIdx = nums.index(min(nums))
        maxIdx = nums.index(max(nums))
        n = len(nums)
        left = min(minIdx, maxIdx)
        right = max(minIdx, maxIdx)
        return min(right+1, n-left, left+1+n-right)
        