class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        nums.sort()
        a = nums[0]
        b = nums[-1]
        newlist = []
        for i in range(a+1, b):
            if i in nums:
                continue
            else:
                newlist.append(i)
        
        return newlist