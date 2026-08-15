/*
36. 有效的数独
中等
请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，
验证已经填入的数字是否有效即可。
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
*/
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, col[9][9] = {0}, box[9][9] = {0};
        int size_r=board.size(), size_c = board[0].size();
        for(int i=0; i<size_r; i++){
            for (int j = 0; j < size_c;j++)
            {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0' - 1;
                if(row[i][num]||col[j][num]||box[i/3*3+j/3][num])
                {
                    return false;
                }
                else
                {
                    row[i][num] = col[j][num] = box[i/3*3+j/3][num] = 1;
                }
            }
        }
        return true;
    }
};


int main(){
    Solution s;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    }
    ;
    cout<<s.isValidSudoku(board)<<endl;
    return 0;
}