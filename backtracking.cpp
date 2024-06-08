// Backtracking template below
void Backtrack(vector<Solution> &res, Args args) {
    if (goalReached(args)) {
        // add solutions to res and then return
        res.push_back(currentSolution(args));
        return;
    }
    for (int i = 0; i < NB_CHOICES; i++) {
        if (isValidChoice(args, i)) { // choice is valid
            makeChoice(args, i); // make choices
            Backtrack(res, args); // backtrack
            undoChoice(args, i); // reverting choices
        }
    }
}

class Solution {
    void backtrack(vector<int>& nums, vector<int>& permutation, vector<vector<int>>& res, vector<bool>& is_seen) {
        if (permutation.size() == nums.size()) res.push_back(permutation);
        for (int i = 0; i < nums.size(); i++) {
            if (!is_seen[i]) { // we have not use it
                is_seen[i] = true;
                permutation.push_back(nums[i]);
                backtrack(nums, permutation, res, is_seen);
                permutation.pop_back();
                is_seen[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> is_seen(nums.size(), false);
        vector<vector<int>> res;
        vector<int> permutation = {};
        backtrack(nums, permutation, res, is_seen);
        return res;
    }
};



// word search
class Solution {
    void backtrack(int r, int c, vector<vector<char>>& board, string& word, int index, bool& found, vector<vector<bool>>& is_seen) {
        if (found || index == word.size()) {
            found = true;
            return;
        }
        static const vector<int> dir = {-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int new_r = r + dir[i], new_c = c + dir[i+1];
            if (new_r >= 0 && new_r < board.size() && new_c >= 0 && new_c < board[0].size() && 
                !is_seen[new_r][new_c] && board[new_r][new_c] == word[index]) {
                is_seen[new_r][new_c] = true;
                backtrack(new_r, new_c, board, word, index + 1, found, is_seen);
                if (found) return; // Early exit if word is found
                is_seen[new_r][new_c] = false;
            }
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if (rows == 0) return false;
        int cols = board[0].size();
        vector<vector<bool>> is_seen(rows, vector<bool>(cols, false));
        bool found = false;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == word[0]) {
                    is_seen[r][c] = true;
                    backtrack(r, c, board, word, 1, found, is_seen);
                    if (found) return true;
                    is_seen[r][c] = false;
                }
            }
        }
        return false;
    }
};
