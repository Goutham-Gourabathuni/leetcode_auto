class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int n0 = 0, q0 = 0, n1 = 0, q1 = 0;
        
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') q0++;
            else n0 += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') q1++;
            else n1 += num[i] - '0';
        }
        
        return (q0 + q1) % 2 == 1 || n0 - n1 != (q1 - q0) * 9 / 2;
    }
};