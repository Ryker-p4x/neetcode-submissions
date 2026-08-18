class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;
        unordered_map<char, int> hash2;
        int len1 = s.size();
        if (len1 != t.size()) {
            return false;
        }
        
        for (char c : s) {
            hash[c]++;
        }
        for (char c : t) {
            hash2[c]++;
        }
        auto it = hash.begin();

        while (it != hash.end()) {
            auto it2 = hash2.find(it->first);

            if (it2 == hash2.end()) {
                return false;
            }

            if (it->first != it2->first || it->second != it2->second) {
                return false;
            }
            ++it;
        }

        return true;
    }
};
