class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;

        while (start < end) {
            while (!isalnum(s[start])) start++;
            while (!isalnum(s[end])) end--;

            if (start < end && toupper(s[start]) != toupper(s[end])) return false;

            start++, end--;
        }

        return true;
    }
};
