/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/
#define _fast_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        _fast_;
        if(grid.size()==0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    islands+=1;
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char> > &grid, int row, int col)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]=='0')
        {
            return;
        }
        if(grid[row][col]=='1') grid[row][col] = '0';
        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);
    }
};
