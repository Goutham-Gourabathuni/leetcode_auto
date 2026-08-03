class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)

        if n<=1:
            return s
        
        start = 0
        maxLen = 1

        for i in range(n):

            # odd len palin
            left = right = i
            
            while left >= 0 and right < n and s[left] == s[right]:
                if right - left + 1  > maxLen:
                    maxLen = right - left + 1
                    start = left
                
                left -= 1
                right += 1
            
            # even len palin

            left = i
            right = i+1

            while left >= 0 and right < n and s[left] == s[right]:
                if right - left + 1  > maxLen:
                    maxLen = right - left + 1
                    start = left
                
                left -= 1
                right += 1
            
        return s[start:start + maxLen]


