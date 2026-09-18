class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1), last(26, -1);
        int n = s.length();
        for (int i = 0; i < n; ++i) last[s[i] - 'a'] = i;
        for (int i = n - 1; i >= 0; --i) first[s[i] - 'a'] = i;
        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; ++i) {
            if (i == first[s[i] - 'a']) {
                int right = last[s[i] - 'a'], j = i;
                bool valid = true;
                while (j <= right) {
                    if (first[s[j] - 'a'] < i) { valid = false; break; }
                    right = max(right, last[s[j] - 'a']); j++;
                }
                if (valid) intervals.push_back({right, i});
            }
        }
        sort(intervals.begin(), intervals.end());
        vector<string> ans; int last_end = -1;
        for (auto& interval : intervals) {
            if (interval.second > last_end) {
                ans.push_back(s.substr(interval.second, interval.first - interval.second + 1));
                last_end = interval.first;
            }
        }
        return ans;
    }
};