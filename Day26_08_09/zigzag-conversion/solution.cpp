/*
6. Z 字形变换
中等
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
*/
#include<string.h>
#include<iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if (size <= numRows || numRows == 1)
        {
            return s;
        }
        string res{};
        res.resize(size);
        int index = 0;
        for (int i = 0; i < numRows; i++)
        {
            int j = i;
            while (j < size)
            {
                res[index++] = s[j];
                if (i != 0 && i != numRows - 1)
                {
                    j += 2 * (numRows - i - 1);
                    if (j < size)
                    {
                        res[index++] = s[j];
                    }
                    j += 2 * i;
                }
                else
                {
                    j += 2 * (numRows - 1);
                }
            }
        }
        return res;
    }
};
int main()
{   
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}