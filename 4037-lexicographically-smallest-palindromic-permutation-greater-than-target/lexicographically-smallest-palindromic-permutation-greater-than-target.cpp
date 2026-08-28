class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        if (n == 1) return s > target ? s : "";
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        string odd_char = "";
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                if (!odd_char.empty()) return "";
                odd_char = string(1, (char)('a' + i));
            }
            cnt[i] /= 2;
        }
        string prefix = "";
        for (int i = 0; i < n / 2; i++) {
            bool placed = false;
            for (int j = 0; j < 26; j++) {
                if (cnt[j] > 0) {
                    cnt[j]--; prefix += (char)('a' + j);
                    string rem_left = "";
                    for (int k = 25; k >= 0; k--) {
                        rem_left += string(cnt[k], (char)('a' + k));
                    }
                    string cand_left = prefix + rem_left;
                    string rev_left = cand_left;
                    reverse(rev_left.begin(), rev_left.end());
                    string cand_pal = cand_left + odd_char + rev_left;
                    if (cand_pal > target) {
                        placed = true; break;
                    }
                    prefix.pop_back(); cnt[j]++;
                }
            }
            if (!placed) return "";
        }
        string rev_final = prefix;
        reverse(rev_final.begin(), rev_final.end());
        return prefix + odd_char + rev_final;
    }
};