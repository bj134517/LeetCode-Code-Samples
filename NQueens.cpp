// Source: https://leetcode.com/problems/n-queens/

/********************************************************************************** 
* 
* The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
* such that no two queens attack each other.
* 
* Given an integer n, return all distinct solutions to the n-queens puzzle.
* The answer could be returned in any order.
* 
* Each solution contains a distinct board configuration of the n-queens' placement, 
* where 'Q' and '.' both indicate a queen and an empty space respectively.
* 
* Example 1:
* Input: n = 4
* Output: [
*           [".Q..",
*            "...Q",
*            "Q...",
*            "..Q."],

*           ["..Q.",
*            "Q...",
*            "...Q",
*            ".Q.."]
*         ]
*
* Example 2:
* Input: n = 1
* Output: [["Q"]]
*               
**********************************************************************************/

// Solution using backtracking
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> chess(n, string(n, '.')); // Initialize chess board
        
        backtrack(ans, chess, 0, 0, n);
        
        return ans;
    }
    
    void backtrack(vector<vector<string>>&ans, vector<string>& chess, int row, int currentQueen, int n){
        // end condition
        if(currentQueen==n){
            ans.push_back(chess);
            return;
        }
        
        for(int col=0; col<n; ++col){
            // if never meet others queen, go backtracking
            if(check(chess, n, row, col)){
                chess[row][col]='Q';
                backtrack(ans, chess, row+1, currentQueen+1, n);
                chess[row][col]='.';
            }
        }
    }
    
    bool check(vector<string>& chess, int n, int row, int col){
        // up, down, left, right
        for(int i=0; i<n; i++){
            if(chess[row][i]=='Q'){
                return false;
            }
            if(chess[i][col]=='Q'){
                return false;
            }
        }
        
        // (-1, -1)
        int r=row, c=col;
        while(r<n && r>=0 && c<n && c>=0){
            if(chess[r][c]=='Q'){
                return false;
            }
            --r;
            --c;
        }
        
        // (1, 1)
        r=row, c=col;
        while(r<n && r>=0 && c<n && c>=0){
            if(chess[r][c]=='Q'){
                return false;
            }
            ++r;
            ++c;
        }
        
        
        // (-1, 1)
        r=row, c=col;
        while(r<n && r>=0 && c<n && c>=0){
            if(chess[r][c]=='Q'){
                return false;
            }
            --r;
            ++c;
        }
        
        // (1, -1)
        r=row, c=col;
        while(r<n && r>=0 && c<n && c>=0){
            if(chess[r][c]=='Q'){
                return false;
            }
            ++r;
            --c;
        }
        
        return true;
    }
};
