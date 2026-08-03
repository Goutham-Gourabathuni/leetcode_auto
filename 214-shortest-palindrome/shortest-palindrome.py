class Solution:
    def shortestPalindrome(self, s: str) -> str:
        rev = s[::-1]
        temp = s + "#" + rev

        lps = [0] * len(temp)

        for i in range(1, len(temp)):
            length = lps[i-1]

            while length>0 and temp[i] != temp[length]:
                length = lps[length -1]
            
            if temp[i] == temp[length]:
                length += 1
            
            lps[i] = length
        
        longest = lps[-1]

        add = s[longest:]

        return add[::-1] + s
        # start =0
        # maxLen =1