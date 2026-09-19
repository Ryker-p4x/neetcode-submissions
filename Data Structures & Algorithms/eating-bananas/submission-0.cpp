class Solution {
public:
    int getAmountOfHours(vector<int>& piles, int k) {
        int hours = 0;

        for (int num : piles) {
            hours += (num + k - 1) / k;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *std::max_element(std::begin(piles), std::end(piles));
        int low = 1;
        int res = high;
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            
            int hours = getAmountOfHours(piles, mid);

            if (hours > h) {
                low = mid + 1;
            } else {
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};
