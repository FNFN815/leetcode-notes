/*
73. 矩阵置零
中等
给定一个 m x n 的矩阵，如果一个元素为 0 ，
则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
*/
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool row0 = false;
        bool col0 = false;
        //判断第一行和第一列是否有
        for (int i = 0; i < row;i++)
        {
            if(matrix[i][0]==0)
            {
                col0 = true;
                break;
            }
        }
        for (int i = 0; i < col;i++)
        {
            if(matrix[0][i]==0)
            {
                row0 = true;
                break;
            }
        }
        //判断除了第一行和第一列的元素是否有0
        for (int i = 1; i < row;i++)
        {
            for (int j = 1; j < col;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //根据第一行和第一列的元素是否为0，将对应的行和列置为0
        for (int i = 1; i < row;i++)
        {
            for (int j = 1; j < col;j++)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        //根据第一行和第一列的元素是否为0，将第一行和第一列置为0
        if(row0)
        {
            for (int i = 0; i < col;i++)
            {
                matrix[0][i] = 0;
            }
        }
        if(col0)
        {
            for (int i = 0; i < row;i++)
            {
                matrix[i][0] = 0;
            }
        }

    }
};
int main()
{   
    Solution s;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    s.setZeroes(matrix);
    for (int i = 0; i < matrix.size();i++)
    {
        for (int j = 0; j < matrix[0].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}