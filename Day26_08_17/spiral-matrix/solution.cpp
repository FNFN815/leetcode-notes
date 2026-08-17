/*
54. 螺旋矩阵
中等
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        int size = matrix.size() * matrix[0].size();
        vector<int> res;
        res.reserve(size);

        while (top <= bottom && left <= right) {
            
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            ++top;

            if (top > bottom) break;
            for (int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            --right;

            if (left > right) break;
            for (int i = right; i >= left; --i) {
                res.push_back(matrix[bottom][i]);
            }
            --bottom;

            if (top > bottom) break;
            for (int i = bottom; i >= top; --i) {
                res.push_back(matrix[i][left]);
            }
            ++left;
        }

        return res;
    }
};


int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = s.spiralOrder(matrix);
    for (int i = 0; i < res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}