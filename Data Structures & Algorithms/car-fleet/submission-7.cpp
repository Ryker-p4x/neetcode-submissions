class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        std::vector<std::pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }

        std::sort(cars.begin(), cars.end(), std::greater<std::pair<int, int>>());

        std::stack<double> stck;
        for (int i = 0; i < n; i++) {
            double current_time = (double)(target - cars[i].first) / cars[i].second;
            if (stck.empty() || current_time > stck.top()) {
                stck.push(current_time);
            }
        }
        return stck.size();
    }
};
