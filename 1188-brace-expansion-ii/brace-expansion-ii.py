class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:

        def add(A, B):
            # Union
            return A | B

        def multiply(A, B):
            # Concatenation
            return {a + b for a in A for b in B}

        def parse(i):
            """
            Returns:
                (set of possible strings, next index)
            """

            result = set()
            current = {""}

            while i < len(expression) and expression[i] != '}':
                
                if expression[i] == ',':
                    # Finish current expression and union it
                    result |= current
                    current = {""}
                    i += 1

                elif expression[i] == '{':
                    # Parse everything inside {}
                    sub, i = parse(i + 1)

                    # Concatenate with current
                    current = multiply(current, sub)

                else:
                    # Lowercase letter
                    current = multiply(current, {expression[i]})
                    i += 1

            # Add the last expression
            result |= current

            # Skip '}'
            if i < len(expression) and expression[i] == '}':
                i += 1

            return result, i

        ans, _ = parse(0)

        return sorted(ans)