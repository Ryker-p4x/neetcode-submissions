class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        std::vector<int> prefixMax(n);
        std::vector<int> suffixMax(n);
        int totalWater = 0;

        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = std::max(prefixMax[i - 1], height[i]);
        }

        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = std::max(suffixMax[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++) {
            totalWater += min(prefixMax[i], suffixMax[i]) - height[i];
        }

        return totalWater;
    }
};
