class Solution:
    def checkValidString(self, s: str) -> bool:
        low = 0
        high = 0

        for ch in s:

            if ch == '(':
                low += 1
                high += 1

            elif ch == ')':
                low -= 1
                high -= 1

            else:  # '*'
                low -= 1
                high += 1

            # Even the maximum possible balance is negative
            # -> impossible
            if high < 0:
                return False

            # Minimum balance cannot be negative
            low = max(0, low)

        # We need some possibility with balance 0
        return low == 0