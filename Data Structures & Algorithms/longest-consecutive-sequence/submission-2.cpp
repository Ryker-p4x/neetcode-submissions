#include <vector>
#include <algorithm>
#include <cstdint>
#include <climits>
#include <iostream>

struct DSUNode {
    int key;
    int parent;
    int sz;
    int stamp;
};

static constexpr int CAP = 1 << 18; // 262,144 slots (< 40% load factor for N = 10^5)
static constexpr int MASK = CAP - 1;
static DSUNode table[CAP];
static int cur_stamp = 0;

// Re-attach Fast I/O
static const auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
    inline int hash_fn(int x) const {
        return (static_cast<uint32_t>(x) * 0x9e3779b9u) & MASK;
    }

    inline int find_dsu(int i) {
        int root = i;
        while (root != table[root].parent) {
            root = table[root].parent;
        }
        int curr = i;
        while (curr != root) {
            int nxt = table[curr].parent;
            table[curr].parent = root;
            curr = nxt;
        }
        return root;
    }

    inline void unite_dsu(int i, int j, int& max_sz) {
        int pi = find_dsu(i), pj = find_dsu(j);
        if (pi != pj) {
            if (table[pi].sz < table[pj].sz) std::swap(pi, pj);
            table[pj].parent = pi;
            table[pi].sz += table[pj].sz;
            if (table[pi].sz > max_sz) max_sz = table[pi].sz;
        }
    }

    // Insert slot, sets is_new to false if duplicate
    inline int get_or_insert_slot(int val, bool& is_new) {
        int i = hash_fn(val);
        while (table[i].stamp == cur_stamp) {
            if (table[i].key == val) {
                is_new = false;
                return i;
            }
            i = (i + 1) & MASK;
        }
        table[i].stamp = cur_stamp;
        table[i].key = val;
        table[i].parent = i;
        table[i].sz = 1;
        is_new = true;
        return i;
    }

    inline int find_slot(int val) const {
        int i = hash_fn(val);
        while (table[i].stamp == cur_stamp) {
            if (table[i].key == val) return i;
            i = (i + 1) & MASK;
        }
        return -1;
    }

public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        cur_stamp++; // Instant O(1) memory reset
        int max_sz = 1;

        // Single Pass with Duplicate Skipping
        for (int n : nums) {
            bool is_new = false;
            int curr_slot = get_or_insert_slot(n, is_new);
            
            // SKIP DUPLICATES INSTANTLY
            if (!is_new) continue;

            if (n > INT_MIN) {
                int prev_slot = find_slot(n - 1);
                if (prev_slot != -1) unite_dsu(curr_slot, prev_slot, max_sz);
            }
            if (n < INT_MAX) {
                int next_slot = find_slot(n + 1);
                if (next_slot != -1) unite_dsu(curr_slot, next_slot, max_sz);
            }
        }

        return max_sz;
    }
};