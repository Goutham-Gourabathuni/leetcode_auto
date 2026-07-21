class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Determine sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        int ans = 0;

        // Read digits
        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Overflow check
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > 7)) {

                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return sign * ans;
    }
};