#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // 1. Scan nums to find the exact boundaries: O(N)
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        int min_val = *min_it;
        int max_val = *max_it;

        // 2. Dynamically allocate ONE flat block of memory based on those bounds
        // This acts exactly like your std::array, keeping all items side-by-side!
        int range = max_val - min_val + 1;
        std::vector<int> numbs(range, 0);

        // 3. Count frequencies using the dynamic coordinate shift
        for (int x : nums) {
            numbs[x - min_val]++; // Subtracting min_val maps the lowest number to index 0
        }

        // 4. Use the Bucket Sort collection concept instead of max_element 
        // This avoids rescanning the array repeatedly and drops runtime to O(N)
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (int i = 0; i < range; i++) {
            if (numbs[i] > 0) {
                int original_num = i + min_val; // Revert the coordinate shift
                buckets[numbs[i]].push_back(original_num);
            }
        }

        // 5. Gather the top k elements from the buckets
        std::vector<int> arr;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                arr.push_back(num);
                if (arr.size() == k) {
                    return arr;
                }
            }
        }

        return arr;
    }
};
