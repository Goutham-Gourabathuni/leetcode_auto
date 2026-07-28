class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> freq(26, 0);

        // Count frequency
        for (char ch : s)
            freq[ch - 'a']++;

        string left = "";
        string mid = "";

        // Build left half and middle
        for (int i = 0; i < 26; i++) {

            left += string(freq[i] / 2, char(i + 'a'));

            if (freq[i] % 2 == 1)
                mid = char(i + 'a');
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};