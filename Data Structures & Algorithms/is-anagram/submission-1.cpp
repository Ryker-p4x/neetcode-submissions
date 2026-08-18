class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length();
        if (len1 != t.length()) {
            return false;
        }
        
        vector<int> count(26, 0);
        for (int i = 0; i < len1; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }

        return true;
    }
};
