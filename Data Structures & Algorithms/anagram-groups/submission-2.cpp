class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<std::string, std::vector<string>> hash_map;
        vector<vector<string>> res;

        for (const string& str : strs) {
            string key = str;
            std::sort(key.begin(), key.end());

            hash_map[key].push_back(str);
        }

        for (const auto& [key, value] : hash_map) {
            res.push_back({value});
        }

        return res;
    }
};
