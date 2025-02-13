#include<bits/stdc++.h>
using namespace std;
/*
Problem Statement:
    Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.

Example 1:

    Input: board =
    [["5","3",".",".","7",".",".",".","."]
    ,["6",".",".","1","9","5",".",".","."]
    ,[".","9","8",".",".",".",".","6","."]
    ,["8",".",".",".","6",".",".",".","3"]
    ,["4",".",".","8",".","3",".",".","1"]
    ,["7",".",".",".","2",".",".",".","6"]
    ,[".","6",".",".",".",".","2","8","."]
    ,[".",".",".","4","1","9",".",".","5"]
    ,[".",".",".",".","8",".",".","7","9"]]
    Output: true

Constraints:

    board.length == 9
    board[i].length == 9
    board[i][j] is a digit 1-9 or '.'.

Approach 1:
    1) Row and Col  parallay read read and Row[1-9] and Col[1-9] map frequncy count when visit
    2) 3x3 tackle sub-boxes [1-9]
    3) split it in 3 problem
       - Solve row [HashSet frequency count]
       - Solve col
       - Solve boxes

       Cell identify formula
        row/3 + 3 + Col/3

    NOw
        -> Row, col, Box
        -> 9 , 9, 9 HashSet

    3) TC: O(n^2) and SC: O(n)


*/
bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<char> row[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                if(board[r][c] == '.')
                {
                    continue;
                }
                char value = board[r][c];
                int boxIndex = (r/3) * 3 + (c/3);

                if(row[r].count(value) || cols[c].count(value) || boxes[boxIndex].count(value))
                {
                    return false;
                }

                row[r].insert(value);
                cols[c].insert(value);
                boxes[boxIndex].insert(value);
            }

        }
        return true;
}

int main()
{


    return 0;
}
