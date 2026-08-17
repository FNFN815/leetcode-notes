/*
289. 生命游戏
中等
根据 百度百科 ， 生命游戏 ，简称为 生命 ，
是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。
每个细胞都具有一个初始状态： 1 即为 活细胞 （live），或 0 即为 死细胞 （dead）。
每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，
其中细胞的出生和死亡是 同时 发生的。给你 m x n 网格面板 board 的当前状态，
返回下一个状态。
给定当前 board 的状态，更新 board 到下一个状态。
注意 你不需要返回任何东西
*/
#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>> &board){
        int m = board.size();
        int n = board[0].size();
        //相邻位置的坐标
        int dirs[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1}, 
            {0, -1}, {0, 1}, 
            {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < m;i++)
        {
            for (int j = 0; j < n;j++)
            {
                int liveNum = 0;
                for(auto &dir:dirs)
                {   
                    //x和y是当前细胞的邻居坐标
                    int x = i + dir[0];
                    int y = j + dir[1];
                    //判断邻居坐标是否合法
                    if(x>=0&&x<m&&y>=0&&y<n)
                    {
                        //判断邻居细胞是否存活
                        if(board[x][y]==1||board[x][y]==-1)
                        {   
                            // 统计周围存活的细胞数量
                            liveNum++;
                        }
                    }
                }
                //判断当前细胞是否存活
               int cur = board[i][j];
                if(cur==1)
                {
                    if(liveNum<2||liveNum>3)
                    {
                        board[i][j] = -1;
                    }
                }
                else
                {
                    if(liveNum==3)
                    {
                        board[i][j] = 2;
                    }
                }

            }
        }
        //将-1和2转换回0和1
        for (int i = 0; i < m;i++)
        {
            for (int j = 0; j < n;j++)
            {
                if(board[i][j]==-1)
                {
                    board[i][j] = 0;
                }
                else if(board[i][j]==2)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
};
int main()
{   
    Solution s;
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    s.gameOfLife(board);
    for(auto &row:board)
    {
        for(auto &cell:row)
        {
            cout<<cell<<" ";
        }
        cout<<endl;
    }

    return 0;
}