/*14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/
#include <string>
#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size == 0) return "";
        int len = strs[0].size();
        for (int i = 0; i < len;i++)
        {
            char c = strs[0][i];
            for (int j = 1; j < size;j++)
            {
                if(i==strs[j].size()||strs[j][i]!=c)
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
int main()
{
    Solution s;
    vector<string> strs = { "flower", "flow", "flight" };
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}