class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        while True:
            prod = 1
            temp = n
            while temp > 0:
                prod = prod*(temp%10)
                temp = temp//10
                if prod == 0:
                    break
            
            if prod%t==0: return n
            else: n = n+1
        