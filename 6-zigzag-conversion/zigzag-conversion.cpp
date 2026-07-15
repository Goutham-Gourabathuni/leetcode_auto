class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        string t = "";
        int n = s.size();
        int cycle = 2 * (numRows - 1);

        for (int row = 0; row < numRows; row++) {

            int j = row;
            bool toggle = true;

            while (j < n) {

                t += s[j];

                // First and last rows
                if (row == 0 || row == numRows - 1) {
                    j += cycle;
                }
                // Middle rows
                else {
                    int down = cycle - 2 * row;
                    int up = 2 * row;

                    if (toggle)
                        j += down;
                    else
                        j += up;

                    toggle = !toggle;
                }
            }
        }

        return t;
    }
};