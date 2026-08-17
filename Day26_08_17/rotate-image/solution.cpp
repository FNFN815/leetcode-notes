/*
48. 旋转图像
中等
给定一个 n × n 的二维矩阵 matrix 表示一个图像。
请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。
请不要 使用另一个矩阵来旋转图像。
*/
#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        // 每一行（row/2)都进行交换,让矩形对称
        for (int i = 0; i < row / 2;i++)
        {
            swap(matrix[i], matrix[row - 1 - i]); 
            
        }
        //关于对称轴交换
        for (int i = 0; i < row;i++)
        {
            for (int j = i + 1; j < col;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
int main(){
    Solution s;
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    s.rotate(matrix);
    for (int i = 0; i < matrix.size();i++)
    {
        for (int j = 0; j < matrix[0].size();j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}