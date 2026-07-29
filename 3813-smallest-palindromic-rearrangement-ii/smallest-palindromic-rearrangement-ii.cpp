class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> bucket(26, 0);
        for (char c : s) bucket[c - 'a']++;
        int partition = s.length() / 2;
        string leftHalf = "";

        auto comb = [](int n, int m, int k_limit) -> long long {
            long long res = 1;
            m = min(m, n - m);
            for (int i = 1; i <= m; i++) {
                res = res * (n - i + 1) / i;
                if (res > k_limit) return (long long)k_limit + 1;
            }
            return res;
        };

        auto permutations = [&](int rem) -> long long {
            long long ways = 1;
            for (int i = 0; i < 26; i++) {
                int pairs = bucket[i] / 2;
                if (pairs == 0) continue;
                ways *= comb(rem, pairs, k);
                rem -= pairs;
                if (ways > k) return (long long)k + 1;
            }
            return ways;
        };

        for (int p = 0; p < partition; p++) {
            bool found = false;
            for (int i = 0; i < 26; i++) {
                if (bucket[i] < 2) continue;
                bucket[i] -= 2;
                long long ways = permutations(partition - 1 - p);
                if (ways >= k) {
                    leftHalf += (char)(i + 'a');
                    found = true;
                    break;
                } else {
                    k -= ways;
                    bucket[i] += 2;
                }
            }
            if (!found) return "";
        }

        string mid = "";
        for (int i = 0; i < 26; i++) {
            if (bucket[i] % 2 != 0) {
                mid = (char)(i + 'a');
                break;
            }
        }

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        return leftHalf + mid + rightHalf;
    }
};