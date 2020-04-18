/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the 
sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //Bottom Up or Pure DP!
        _fast_;
        int m = grid.size(); //rows
        int n = grid[0].size(); //columns
        if(!m)
            return 0;
        if(!n)
            return 0;
        vector<vector<int>> helperGrid(m, vector<int>(n, 0));
        //along first row
        helperGrid[0][0] = grid[0][0];
        for(int i=1; i<n; i++)
        {
            helperGrid[0][i] = helperGrid[0][i-1] + grid[0][i];
        }
        //along first column
        for(int j=1; j<m; j++)
        {
            helperGrid[j][0] = helperGrid[j-1][0] + grid[j][0];
        }
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                helperGrid[i][j] = min((helperGrid[i-1][j]+grid[i][j]), (helperGrid[i][j-1]+grid[i][j]));
            }
            cout << endl;
        }
        
        return helperGrid[m-1][n-1];
    }
};
