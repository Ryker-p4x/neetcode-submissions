class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> box; 

        for (int i = 0; i < 9; i++) {
            std::unordered_set<char> row;
            std::unordered_set<char> col;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int current_box = (i / 3) * 3 + (j / 3);
                    if (row.find(board[i][j]) != row.end() || box[current_box].find(board[i][j]) != box[current_box].end()) {
                        return false;
                    }
                    row.insert(board[i][j]);
                    box[current_box].insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    int current_box = (j / 3) * 3 + (i / 3);
                    if (col.find(board[j][i]) != col.end()) {
                        return false;
                    }
                    col.insert(board[j][i]);
                }
            }
        }

        return true;
    }
};
