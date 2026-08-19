class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;

        for (const auto& str : strs) {
            string res = str + "․";

            encoded_string += res;
        }
        
        return encoded_string;
    }

    vector<string> decode(string s) {
        int capacity = 5;
        vector<string> decoded_string;
        decoded_string.reserve(capacity);

        string word;

        for (size_t i = 0; i < s.size();) {
            if (decoded_string.size() == capacity) {
                decoded_string.reserve(capacity);
            }
            if (s.compare(i, 3, "\u2024") == 0) {
                decoded_string.push_back(word);
                word.clear();

                i += 3;
                continue;
            }

            word += s[i];
            i++;
        }
        return decoded_string;
    }
};
