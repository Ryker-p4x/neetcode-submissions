class Solution {
public:
    void cleanString(std::string& str) {
        // Remove if the character is NOT alphanumeric
        str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char c) {
            return !std::isalnum(c); 
        }), str.end());

        // Convert what remains to lowercase
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
    }

    bool isPalindrome(string s) {
        cleanString(s);
        string reverted_string;
        for (int i = s.size() - 1; i >= 0; i--) {
            reverted_string += s[i];
        }

        if (reverted_string == s) {
            return true;
        } else {
            return false;
        }
    }
};
