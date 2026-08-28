class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> solutions;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate values for the first element to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int l = i + 1;
            int r = nums.size() - 1;
            
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum == 0) {
                    solutions.push_back({nums[i], nums[l], nums[r]});
                    
                    // Skip duplicates for the left pointer
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    // Skip duplicates for the right pointer
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    
                    // Move both pointers inward
                    l++;
                    r--;
                } 
                else if (sum < 0) {
                    l++; // Sum is too small, move left pointer to get a larger number
                } 
                else {
                    r--; // Sum is too big, move right pointer to get a smaller number
                }
            }
        }
        return solutions;
    }
};
