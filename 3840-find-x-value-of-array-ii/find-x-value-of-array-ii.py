from typing import List


class Solution:
    def resultArray(self, nums: List[int], k: int, queries: List[List[int]]) -> List[int]:

        n = len(nums)

        # tree[node] = [product_mod_k, count_of_prefixes_for_each_remainder]
        #
        # Example:
        # tree[node][0] = product of entire segment % k
        # tree[node][1][r] = number of non-empty prefixes
        #                  having product % k == r
        tree = [[1, [0] * k] for _ in range(4 * n)]

        def make_leaf(value):
            p = value % k
            cnt = [0] * k
            cnt[p] = 1
            return p, cnt

        def merge(left, right):
            lp, lc = left
            rp, rc = right

            # Product of the complete combined segment
            product = (lp * rp) % k

            cnt = lc[:]

            # Prefixes that enter the right segment
            # already have product lp.
            for r in range(k):
                new_rem = (lp * r) % k
                cnt[new_rem] += rc[r]

            return product, cnt

        def build(node, l, r):
            if l == r:
                tree[node] = list(make_leaf(nums[l]))
                return

            mid = (l + r) // 2

            build(node * 2, l, mid)
            build(node * 2 + 1, mid + 1, r)

            tree[node] = list(
                merge(tree[node * 2], tree[node * 2 + 1])
            )

        def update(node, l, r, pos, value):
            if l == r:
                tree[node] = list(make_leaf(value))
                return

            mid = (l + r) // 2

            if pos <= mid:
                update(node * 2, l, mid, pos, value)
            else:
                update(node * 2 + 1, mid + 1, r, pos, value)

            tree[node] = list(
                merge(tree[node * 2], tree[node * 2 + 1])
            )

        def query(node, l, r, ql, qr):
            # Completely outside
            if r < ql or qr < l:
                return None

            # Completely inside
            if ql <= l and r <= qr:
                return tree[node]

            mid = (l + r) // 2

            left = query(node * 2, l, mid, ql, qr)
            right = query(node * 2 + 1, mid + 1, r, ql, qr)

            if left is None:
                return right

            if right is None:
                return left

            return merge(left, right)

        build(1, 0, n - 1)

        ans = []

        for index, value, start, x in queries:

            # This update persists for future queries.
            nums[index] = value
            update(1, 0, n - 1, index, value)

            # After removing nums[0:start],
            # possible remaining arrays are:
            #
            # nums[start:start+1]
            # nums[start:start+2]
            # ...
            # nums[start:n]
            #
            # These are exactly the non-empty prefixes of
            # nums[start:n].
            _, cnt = query(1, 0, n - 1, start, n - 1)

            ans.append(cnt[x])

        return ans