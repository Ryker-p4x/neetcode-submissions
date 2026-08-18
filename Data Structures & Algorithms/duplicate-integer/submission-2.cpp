class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hash_set;

        for (int n : nums) {
            if (hash_set.contains(n)) {
                return true;
            }
            hash_set.insert(n);
        }
        
        return false;
    }
};