class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. optional sign (only one)
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. read digits with overflow check before multiplying
        int res = 0;
        while (i < n && isdigit(s[i])) {
            int d = s[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && d > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + d;
            i++;
        }

        // 4. apply sign
        return res * sign;
    }
};