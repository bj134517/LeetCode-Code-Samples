// Source: https://leetcode.com/problems/number-of-islands/

/********************************************************************************** 
 * 
 * Given an m * n 2D binary grid which represents a map of '1's (land) and '0's (water), 
 * return the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands 
 * horizontally or vertically. You may assume all four edges of the grid are all
 * surrounded by water.
 * 
 * Example 1:
 * Input: grid = [
 *   ["1","1","1","1","0"],
 *   ["1","1","0","1","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 * Example 2:
 * Input: grid = [
 *   ["1","1","0","0","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","1","0","0"],
 *   ["0","0","0","1","1"]
 * ]
 * Output: 3
 *               
 **********************************************************************************/

// Solution using Breadth-First Search
class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        int number_of_island = 0;
        
        // Loop through the grid
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                // We find an island or piece of an island
                if (grid[i][j] == '1') {
                    ++number_of_island;
                    
                    // Use Breadth-First Search to mark all pieces of current island to '0'
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        int x = p.first, y = p.second;
                        q.pop();
                        
                        // Down
                        if (x+1 < grid.size() and grid[x+1][y] == '1') {
                            q.push({x+1, y});
                            grid[x+1][y] = '0';
                        }
                        // Up
                        if (x-1 >= 0 and grid[x-1][y] == '1' ) {
                            q.push({x-1, y});
                            grid[x-1][y] = '0';
                        }
                        // Right
                        if (y+1 < grid[0].size() and grid[x][y+1] == '1') {
                            q.push({x, y+1});
                            grid[x][y+1] = '0';
                        }
                        // Left
                        if (y-1 >= 0 and grid[x][y-1] == '1') {
                            q.push({x, y-1});
                            grid[x][y-1] = '0';
                        }
                    }
                }
            }
        }
        
        
        return number_of_island;
    }
};
