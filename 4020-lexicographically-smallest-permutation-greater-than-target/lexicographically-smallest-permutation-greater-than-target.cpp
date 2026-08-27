#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string lexGreaterPermutation(std::string s, std::string target) {
        std::vector<int> cnt(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
            cnt[target[i] - 'a']--;
        }
        
        std::string t = target;
        for (int i = n - 1; i >= 0; i--) {
            int b = t[i] - 'a';
            cnt[b]++;
            
            int min_val = 0;
            for (int c : cnt) min_val = std::min(min_val, c);
            if (min_val < 0) continue;
            
            for (int j = b + 1; j < 26; j++) {
                if (cnt[j] > 0) {
                    cnt[j]--;
                    t[i] = 'a' + j;
                    std::string res = t.substr(0, i + 1);
                    for (int k = 0; k < 26; k++) {
                        res.append(cnt[k], 'a' + k);
                    }
                    return res;
                }
            }
        }
        return "";
    }
};