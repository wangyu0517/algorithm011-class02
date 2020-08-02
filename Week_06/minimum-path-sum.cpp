//思路：局部最小不一定最终最小，必须遍历所有可能的
//dp[i,j] = min(dp[i-1, j], dp[i, j-1])
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int rows = grid.size(), columns = grid[0].size();
        auto dp = vector < vector <int> > (rows, vector <int> (columns));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++) {//走边缘
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < columns; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][columns - 1];
    }

//递归求
    // int dp(int i, int j, int x, int y, vector<vector<int>>& grid){
    //     if(i == x && j==y) return grid[i][j];
    //     if(i == x) return grid[i][j] + dp(i, j+1, x, y, grid);
    //     if(j == y) return grid[i][j] + dp(i+1, j, x, y, grid);
    //     return grid[i][j] + min(dp(i+1, j, x, y, grid), dp(i, j+1, x, y, grid));
    // }
};