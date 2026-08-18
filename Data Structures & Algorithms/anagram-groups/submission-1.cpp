class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<std::string, std::vector<string>> hash_map;
        vector<vector<string>> res;

        for (int i = 0; i < strs.size(); i++) {

            std::string temp = strs[i];

            std::sort(strs[i].begin(), strs[i].end());

            if (hash_map.find(strs[i]) != hash_map.end()) {
                auto it = hash_map.find(strs[i]);
                it->second.push_back(temp);
            } else {
                hash_map[strs[i]].push_back(temp);
            }
        }

        for (const auto& [key, value] : hash_map) {
            res.push_back({value});
        }

        return res;
    }
};
