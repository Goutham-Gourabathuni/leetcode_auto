class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        # nums.sort()
        # a = nums[0]
        # b = nums[-1]
        # newlist = []
        # for i in range(a+1, b):
        #     if i in nums:
        #         continue
        #     else:
        #         newlist.append(i)
        
        # return newlist

        st = set(nums)
        mn = min(nums)
        mx = max(nums)
        return [x for x in range(mn+1, mx) if x not in nums]