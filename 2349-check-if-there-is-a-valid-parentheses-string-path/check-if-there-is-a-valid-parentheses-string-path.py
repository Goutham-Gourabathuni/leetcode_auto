class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        m = len(grid)
        n = len(grid[0])

        # Valid parentheses string must have even length
        if (m + n - 1) % 2 == 1:
            return False

        # First and last characters must be '(' and ')'
        if grid[0][0] == ')' or grid[m - 1][n - 1] == '(':
            return False

        # dp[j] = set of possible balances at current row, column j
        dp = [[set() for _ in range(n)] for _ in range(m)]

        dp[0][0].add(1)

        for i in range(m):
            for j in range(n):

                if i == 0 and j == 0:
                    continue

                # Get possible balances from top and left
                prev = set()

                if i > 0:
                    prev |= dp[i - 1][j]

                if j > 0:
                    prev |= dp[i][j - 1]

                # Update balance based on current character
                if grid[i][j] == '(':
                    change = 1
                else:
                    change = -1

                for balance in prev:
                    new_balance = balance + change

                    # Balance can never be negative
                    if new_balance >= 0:
                        dp[i][j].add(new_balance)

        # Valid iff we can reach final cell with balance 0
        return 0 in dp[m - 1][n - 1]